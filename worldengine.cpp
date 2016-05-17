#include "worldengine.hpp"

Worldengine::Worldengine(sf::RenderWindow *t_app,b2World *t_world) :
p_app(t_app),p_world(t_world)
{
    view_factor = 1;					//eteblit le facteur de vue a 1 
    view_factor2 = 1;	
    p_gengine = new G_engine(p_app);	// cree un object graphique
    view = 1;						//vu par defaut (vaisseaux)
    
    e_clear = true;
    
    p_coleng = new Collision_engine();
    
    p_world->SetContactListener(p_coleng); //insere mon test de collision dans le monde box2d
    
    
    
    /*creation du systeme solaire
     * on cree un pointer vers une planete puis on alloue dynamiquement une planete 
     * que l'on initialise avec des parametres predefinis tel que le nom la densite la position ect
     * on ajoute ensuite le pointer dans un deque (liste)*/

    Planete *p_sun;
    p_sun = new Planete(p_gengine,SUN_TEXTURE,p_world,1,0.5f,0,0,0,100,100,SUN_RADIUS,0);
    de_planete.push_back(p_sun);
    
   /* Planete *p_mercure;
    p_mercure = new Planete(p_gengine,MERCURE_TEXTURE,p_world,1,0.5f,0,MERCURE_STARTPOS,0,100,100,MERCURE_RADIUS,0);
    de_planete.push_back(p_mercure);*/
    
   /* Planete *p_venus;
    p_venus = new Planete(p_gengine,VENUS_TEXTURE,p_world,1,0.5f,0,0,VENUS_STARTPOS,100,100,VENUS_RADIUS,0);
    de_planete.push_back(p_venus);
    
    Planete *p_earth;
    p_earth = new Planete(p_gengine,EARTH_TEXTURE,p_world,1,0.5f,0,0,-EARTH_STARTPOS,100,100,EARTH_RADIUS,0);
    de_planete.push_back(p_earth);
      
     Planete *p_moon;
    p_moon = new Planete(p_gengine,MOON_TEXTURE,p_world,1,0.5f,0,0,-EARTH_STARTPOS - 2000 ,100,100,MOON_RADIUS,0);
    de_planete.push_back(p_moon);*/
    
     /*Planete *p_planete5;
    p_planete5 = new Planete(p_gengine,MERCURE_TEXTURE,p_world,1,0.5f,0,-30000,0,100,100,MERCURE_RADIUS,0);
    de_planete.push_back(p_planete5);*/
    
    
    /* Planete *p_planete6;
    p_planete6 = new Planete(p_gengine,MERCURE_TEXTURE,p_world,1,0.5f,0,-40000,0,100,100,MERCURE_RADIUS,0);
    de_planete.push_back(p_planete6);*/
    
    /*
    Planete *p_planete3;
    p_planete3 = new Planete(p_gengine,SAT_TEXTURE,p_world,1,0.5f,0,32400,0,100,100,SAT_RADIUS,0);
    de_planete.push_back(p_planete3);*/
    
    
//     creation des Vaisseaux

    Vaisseaux *p_vaisseaux;
    p_vaisseaux = new Vaisseaux(p_gengine,"vaisseaux",p_world,0.1f,0.0f,0.2f,-800,60000,60,140,0,0.1,0.1);
    de_vaisseaux.push_back(p_vaisseaux);
    
    Vaisseaux *p_vaisseaux2;
    p_vaisseaux2 = new Vaisseaux(p_gengine,"vaisseaux",p_world,0.1f,0.0f,0.2f,800,60000,60,140,0,0.1,0.1);
    de_vaisseaux.push_back(p_vaisseaux2);
    
    //Demmarage de differentes horloge pour des mesure de temps
    clock_rate_fire.restart();
     clock_rate_fire2.restart();
    clock_rate_touche.restart();
    clock_gravstep.restart();
    clock_display.restart();	
    
    //initialise la vitesse de depart des planete pour leur orbite
    lanceplanete();
}
Worldengine::~Worldengine()//destruction de tout les objet cree dans le monde
{
    
    for (int i=0; i<de_corpsfix.size(); ++i)  //boucle pour suprimer les corps fixes
     {
        delete de_corpsfix.at(i);
     }
     for (int i=0; i<de_corps.size(); ++i)  //boucle pour suprimer les corps
     {
        delete de_corps.at(i);
     }
     for (int i=0; i<de_vaisseaux.size(); ++i)  //boucle pour suprimer les Vaisseaux
     {
        delete de_vaisseaux.at(i);
     }
     for (int i=0; i<de_planete.size(); ++i)  //boucle pour suprimer les Planetes
     {
        delete de_planete.at(i);
     }
     for (int i=0; i<de_weapons.size(); ++i)  //boucle pour suprimer les armes
     {
        delete de_weapons.at(i);
     }
     
     
    delete p_gengine;
    delete p_coleng;
}
void Worldengine::step(float dt)
{
  sf::Time elapsed00 = clock_gravstep.getElapsedTime();

      clock_gravstep.restart();
      
      grav.step(dt,de_corps,de_planete,de_vaisseaux,de_weapons);
      chargevec_view(view);										//charge la vue a afficher
      p_gengine->Changeview(view_factor,p_vec_view,view_factor2,de_vaisseaux.at(1)->getVvec());				//l'appliquer au monde graphique
      view_factor = 1;											//remettre facteur de vue a 0
      view_factor2 = 1;		
      p_world->Step(dt,VELOCITYITERATIONS, POSITIONITERATIONS);		//actualisation des corp de Box2d (monde physique)
      remove_weapons();


  //Boucle affichage 60 hz SFML on affiche que 60 frame par seconde pour eviter de changer trop de foit
  //les images et permetre au pc d'effectuer le plus possible de foit la boucle de position/gravitation des objet 
  sf::Time elapsed_display = clock_display.getElapsedTime();
    
    if (elapsed_display.asMilliseconds() > 16.66)
    {
      clock_display.restart();
      for (int i=0; i<de_corps.size(); ++i) //boucle actualiser les Corps adapter le sprite a son objet box2d
      {
	de_corps.at(i)->actualise();
      }
      for (int i=0; i<de_vaisseaux.size(); ++i) //boucle actualiser Vaisseaux adapter le sprite a son objet box2d
      {
	if (i == 1)
	{
	  de_vaisseaux.at(1)->actualise(p_gengine->get_viewfactor2());
	}
	else
	{
	  de_vaisseaux.at(i)->actualise(p_gengine->get_viewfactor());
	}
      }
      
      for (int i=0; i<de_planete.size(); ++i) //boucle actualiser Planete adapter le sprite a son objet box2d
      {
	  de_planete.at(i)->actualise();
      }
      for (int i=0; i<de_weapons.size(); ++i)
      {
	  de_weapons.at(i)->actualise();
      }
      if (e_clear == true)
      {
	p_app->clear();
      }
      p_gengine->affiche_sprites(get_world_nb_corps(),elapsed00.asSeconds()); 		//afficher sprite a l'ecran
    }
}
void Worldengine::changeview(int vu,float factor,float factor2)	//change l'echelle de vu est la valeur de view
{
  if (vu != 0)							//pas de changement de vue si agale a 0
  {
    view = vu;
  }
  if (factor != 0)							//pas de changement de vue si agale a 0
  {
    view_factor = view_factor * factor;		// chagement de l'echalle de vu;
  }
  if (factor2 != 0)							//pas de changement de vue si agale a 0
  {
      view_factor2 = view_factor2 * factor2;		// chagement de l'echalle de vu2
  }
}
void Worldengine::chargevec_view(int vie)		//charge les differente vecter vu (vaisseaux1 ,2 ,Soleil,Terre,Lune...)
{
  switch ( vie )
  {
    case 1:
      p_vec_view= de_vaisseaux.at(0)->getVvec();
      break;
    case 2:
      p_vec_view = de_planete.at(0)->getVvec();
      break;
    case 3:
      p_vec_view = de_planete.at(1)->getVvec();
      break;
    case 4:
      p_vec_view = de_planete.at(2)->getVvec();
      break;
	case 5:
      p_vec_view = de_planete.at(3)->getVvec();
      break;
	case 6:
      p_vec_view = de_planete.at(4)->getVvec();
      break;
	case 7:
      p_vec_view = de_planete.at(5)->getVvec();
      break;
	case 8:
      p_vec_view = de_planete.at(6)->getVvec();
      break;
	case 9:
      p_vec_view = de_planete.at(7)->getVvec();
	case 11:
      p_vec_view = de_vaisseaux.at(1)->getVvec();
      break;
    }
}
void Worldengine::controlV1(float nb)
{
    if (nb == 8)
    de_vaisseaux.at(0)->applyForce(1);

    else if (nb == 4)
    de_vaisseaux.at(0)->turnLeft();

    else if (nb == 6)
    de_vaisseaux.at(0)->turnRight();

    else if (nb == 5)
    de_vaisseaux.at(0)->applyForce(-1);
    
    else
    de_vaisseaux.at(0)->default_state();

}
void Worldengine::controlV1_mode(float mode)
{
  de_vaisseaux.at(0)->set_mode(mode);
}
void Worldengine::controlV2(float nb)
{
    if (nb == 8)
    de_vaisseaux.at(1)->applyForce(1);

    else if (nb == 4)
    de_vaisseaux.at(1)->turnLeft();

    else if (nb == 6)
    de_vaisseaux.at(1)->turnRight();

    else if (nb == 5)
    de_vaisseaux.at(1)->applyForce(-1);
    
    else
    de_vaisseaux.at(1)->default_state();
}
void Worldengine::lanceplanete()
{
    for (int i=0; i<de_planete.size(); ++i)
    {
      de_planete.at(i)->secondPini();
    }
}
void Worldengine::V1_fire()
{
  if(de_vaisseaux.at(0)->get_alive() == true)
  {
    sf::Time elapsed = clock_rate_fire.getElapsedTime();
  
    if (elapsed.asMilliseconds() > 100)
    {
      clock_rate_fire.restart();
      sf::Vector2f vvec;
      vvec = de_vaisseaux.at(0)->getVvec();
      
      Weapons *arme;
      arme = new Weapons(de_vaisseaux.at(0)->Getp_body()->GetLinearVelocity(),de_vaisseaux.at(0)->get_angle(),p_gengine,WEAPONS01_TEXTURE,p_world,1,0.5f,0,
			
			vvec.x += cos((de_vaisseaux.at(0)->get_angle() - 90 ) * M_PI / 180.0) * 500 ,
			
			vvec.y += sin((de_vaisseaux.at(0)->get_angle() - 90) * M_PI / 180.0) * 500,
			
			
			10,10,WEAPONS01_RADIUS,0);
      
            arme->set_vaisseaux(1);
      de_weapons.push_back(arme);
    }
  }
}
void Worldengine::V2_fire()
{
  if(de_vaisseaux.at(1)->get_alive() == true)
  {
    sf::Time elapsed = clock_rate_fire2.getElapsedTime();

    if (elapsed.asMilliseconds() > 100)
    {
      clock_rate_fire2.restart();
      sf::Vector2f vvec;
      vvec = de_vaisseaux.at(1)->getVvec();

	Weapons *arme;
      arme = new Weapons(de_vaisseaux.at(1)->Getp_body()->GetLinearVelocity(),de_vaisseaux.at(1)->get_angle(),p_gengine,WEAPONS01_TEXTURE,p_world,1,0.5f,0,
			  
			  vvec.x += cos((de_vaisseaux.at(1)->get_angle() - 90 ) * M_PI / 180.0) * 500 ,
			  
			  vvec.y += sin((de_vaisseaux.at(1)->get_angle() - 90) * M_PI / 180.0) * 500,
			  
			  
			  10,10,WEAPONS01_RADIUS,0);
      
      arme->set_vaisseaux(2);
      de_weapons.push_back(arme);
    }
  }
}

void Worldengine::change_traine()
{
  sf::Time elapsed = clock_rate_touche.getElapsedTime();
 
  if (elapsed.asSeconds() > 1)
  {
    clock_rate_touche.restart();
    if (e_clear == false) { e_clear = true; }
    else { e_clear = false; }
  }
}

int Worldengine::get_world_nb_corps()
{
  return de_corps.size() + de_vaisseaux.size() + de_planete.size() + de_weapons.size();
}

void Worldengine::remove_weapons()
{
  std::deque<Weapons*>::iterator it1;
  
  for (it1 = de_weapons.begin(); it1<de_weapons.end(); it1++)
  {
    if ((*it1)->get_life_time() > 20.f || (*it1)->get_life_time() < 0.f)
    {
      delete (*it1);
      de_weapons.erase(it1);
    }
  }
}
