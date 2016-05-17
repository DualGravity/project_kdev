#include"g_engine.hpp"


G_engine::G_engine(sf::RenderWindow *t_app) :
p_app(t_app)
{
    view_factor = 1;
    view_factor2 = 1;
    
    p_player1View = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(1600, 900));
    p_player1View->setViewport(sf::FloatRect(0, 0, 0.5f, 1));

    p_player2View = new sf::View(sf::Vector2f(0, 0), sf::Vector2f(1200, 800));
    p_player2View->setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1));
    
    
/* Split Screen
player1View.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
player2View.setViewport((sf::FloatRect(0.5f, 0, 0.5f, 1));;*/

    
    p_player1View->zoom(ZOOM);
    p_player2View->zoom(ZOOM);
    
    p_app->setView(*p_player1View);
    p_app->setView(*p_player2View);

    font.loadFromFile("GROBOLD.ttf");
    text.setFont(font);
    text.setString("TRUC POUR FAIRE THECNIQUE");
    text.setCharacterSize(20);
    text.setColor(sf::Color::White);
    
    text2.setFont(font);
    text2.setString("TRUC POUR FAIRE THECNIQUE");
    text2.setCharacterSize(20);
    text2.setColor(sf::Color::White);
    
    clock_global.restart();
    
    pps = 0;
    nb_ob = 0;
}
G_engine::~G_engine()
{

    delete p_player1View;
    delete p_player2View;
    for (int i=0; i<de_sprite.size(); ++i)  //boucle pour afficher tout les sprite de la liste
     {
       delete de_sprite.at(i);
     }
     
         for (int i=0; i<de_texture.size(); ++i)  //boucle pour afficher tout les sprite de la liste
     {
       delete de_texture.at(i);
     }
}
void G_engine::affiche_sprites(int nb_objet,float t_pps)
{
  nb_ob = nb_objet;
  pps = t_pps;
  
  for (int i=0; i<de_sprite.size(); ++i) //boucle pour suprimer tout les sprites en allocation dynamique
  {
    text.setString(affiche_Texte(g_vec));
    text2.setString(affiche_Texte(g_vec2));
    
      p_app->setView(*p_player1View);
      p_app->draw(*de_sprite.at(i));
      p_app->draw(text);

      p_app->setView(*p_player2View);
      p_app->draw(*de_sprite.at(i));
      p_app->draw(text2);
  }
  
  // Update the window
  p_app->display();

}
sf::Sprite* G_engine::create_sprite()
{
  sf::Sprite *p_sprite;
  p_sprite = new sf::Sprite;              //allocation dynamique des sprites

    de_sprite.push_back(p_sprite);          //ajout du sprite deque (liste)
    return p_sprite;                        //return pointer pour que la classe que corps soit lier avec ce sprite

}
void  G_engine::delete_sprite(sf::Sprite *p_sprite)
{
  std::deque<sf::Sprite*>::iterator it1;
  for (it1 = de_sprite.begin(); it1<de_sprite.end(); it1++)	//parcour toute les texture de la liste de_sprite
  {
    if (p_sprite == *it1)		
    {
      delete (*it1);
      de_sprite.erase(it1);						//on supprime de la memoire
    }
  }
}
Texture_engine*  G_engine::create_texture(std::string name)	//Creation de texture
{
  for (int i=0; i<de_texture.size(); ++i)			//parcour toute les texture de la liste de_texture
  {
     if (name == de_texture.at(i)->get_name())	//si une texture existe
     {
       de_texture.at(i)->change_cont(1);			//on rajoute 1 a son conteur
       return de_texture.at(i);					// on retourne le pointer texture qui serat utiiser pour le sprite
     }
  }
  //Si pas encore cree :
  Texture_engine *p_texture;				//creation du pointer
  p_texture = new Texture_engine(name);      //allocation dynamique des Textures
  de_texture.push_back(p_texture);        		//ajout de la texture deque (liste)  
  return p_texture;                       			 //return pointer pour que la classe que corps soit lier avec ce sprite
}

void  G_engine::delete_texture(std::string name)	//Destruction de Texture
{
  std::deque<Texture_engine*>::iterator it1;
  for (it1 = de_texture.begin(); it1<de_texture.end(); it1++)				//parcour toute les texture de la liste de_texture
  {
    if (name == (*it1)->get_name())		//si une texture existe
    {
      (*it1)->change_cont(-1);				//decremente le compteur
      
      if ((*it1)->get_cont() == 0)			//si il ni en a plus
      {
	delete (*it1);
	de_texture.erase(it1);						//on supprime de la memoire
      }
    }
  }
}
void G_engine::Changeview(float factor,sf::Vector2f t_vec,float factor2,sf::Vector2f t_vec2)
{
    p_player1View->setCenter(t_vec);
    p_player2View->setCenter(t_vec2);
    view_factor = factor;
    view_factor2 = factor2;
    g_vec = t_vec;
    g_vec2 = t_vec2;
    
    p_player1View->zoom(view_factor);
    sf::Vector2f a_vec;
    a_vec.x = -p_player1View->getSize().x/2;							//affiche en haut a gauche
    a_vec.y = -p_player1View->getSize().y/2;
    a_vec =  a_vec + t_vec;
    text.setScale((p_player1View->getSize().x)/1000,(p_player1View->getSize().y)/1000);//meme taille de texte peu importe la view
    text.setPosition(a_vec);
    
    
    
    p_player2View->zoom(view_factor2);
    sf::Vector2f a_vec2;
    a_vec2.x = -p_player2View->getSize().x/2;							//affiche en haut a gauche
    a_vec2.y = -p_player2View->getSize().y/2;
    a_vec2 =  a_vec2 + t_vec2;
    text2.setScale((p_player2View->getSize().x)/1000,(p_player2View->getSize().y)/1000);//meme taille de texte peu importe la view
    text2.setPosition(a_vec2);

}

std::string G_engine::affiche_Texte(sf::Vector2f t_vec)
{
    //affichage FPS
    sf::Time FPS = clock.restart();
    float time = 1 / FPS.asSeconds();
    time = round(time);
    std::ostringstream oss;
    oss << time;
    std::string str_FPS = oss.str();
    
    //affichage PPS
    float time_pps = 1 / pps;
    time_pps = round(time_pps);
    std::ostringstream oss_pps;
    oss_pps << time_pps;
    std::string str_PPS = oss_pps.str();
    
    //affichage nb d'objets dans le monde
    std::ostringstream oss_nb;
    oss_nb << nb_ob;
    std::string str_nb = oss_nb.str();

    //affichage Temps global
    sf::Time tempglobal = clock_global.getElapsedTime();
    float timeglob = tempglobal.asSeconds();
    timeglob = round(timeglob);
     std::ostringstream tempgl;
     tempgl << timeglob;
     std::string str_tempm_globale = tempgl.str();

    //position
    float posx = t_vec.x;
    float posy = t_vec.y;
    posx = round(posx);
    posy = round(posy);
    std::ostringstream px;
    px << posx;
    std::string str_POSX = px.str();
    std::ostringstream py;
    py << posy;
    std::string str_POSY = py.str();


    std::string str;
    std::string str_Tfps("FPS : " + str_FPS);
    std::string str_Tpps("\nPPS : " + str_PPS);
    std::string str_Temp("\nTemps : "+ str_tempm_globale );
    std::string str_Tpx("\nPX : "+ str_POSX);
    std::string str_Tpy("\nPY : "+ str_POSY);
    
    std::string str_Tnb("\nCorps : "+ str_nb);
    str = str_Tfps  + str_Tpps +str_Temp +str_Tpx  + str_Tpy + str_Tnb;
    
    return str;

}

float G_engine::get_viewfactor()
{
  return p_player1View->getSize().x;
}
float G_engine::get_viewfactor2()
{
  return p_player2View->getSize().x;
}