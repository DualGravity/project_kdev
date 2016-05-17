#include "texture_engine.hpp"


Texture_engine::Texture_engine(std::string t_name)
{
  name = t_name;	//recupere le nom
  cont = 1;		//initialisation du conteur a 1
  
  
  //Charge differente  Texture suivant le nom
  if (name == "vaisseaux")
  {
    t_texture_default = new sf::Texture;
    t_texture_up = new sf::Texture;
    t_texture_down = new sf::Texture;
    t_texture_left = new sf::Texture;
    t_texture_right = new sf::Texture;
    t_texture_death = new sf::Texture;
    t_texture_ico = new sf::Texture;
    
    t_texture_vie3 = new sf::Texture;
    t_texture_vie2 = new sf::Texture;
    t_texture_vie1 = new sf::Texture;
    t_texture_vie0 = new sf::Texture;
    
    t_texture_default->loadFromFile("Image/vai.bmp");
    t_texture_up->loadFromFile("Image/vaimaa.bmp");
    t_texture_down->loadFromFile("Image/vaimar.bmp");
    t_texture_left->loadFromFile("Image/vaig.bmp");
    t_texture_right->loadFromFile("Image/vaid.bmp");
    t_texture_death->loadFromFile("Image/cb.bmp");
    t_texture_ico->loadFromFile("Image/vai_ico2.bmp");
    
    t_texture_vie3->loadFromFile("Image/vie3.bmp");
    t_texture_vie2->loadFromFile("Image/vie2.bmp");
    t_texture_vie1->loadFromFile("Image/vie1.bmp");
    t_texture_vie0->loadFromFile("Image/vie0.bmp");
    
  }
  
  else if (name == "sun")
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/sun.bmp");
  }
  
  else if (name == "moon")
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/moon.bmp");
  }
  
  else if (name == "mercure")
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/mercure.bmp");
  }
  
    else if (name == "venus")
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/venus.bmp");
  }
  
      else if (name == "earth")
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/earth.bmp");
  }
  
    else if (name == WEAPONS01_TEXTURE)
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/weapons01.bmp");
  }
  
   else
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/cb.bmp");
  }
  
}
Texture_engine::~Texture_engine()
{
  
  //Detruire les Texture
   if (name == "vaisseaux")
  {
   delete  t_texture_default;
   delete  t_texture_up;
   delete  t_texture_down;
   delete  t_texture_left;
   delete t_texture_right;
   delete t_texture_death;
   delete t_texture_ico;
   delete t_texture_vie3;
   delete t_texture_vie2;
   delete t_texture_vie1;
   delete t_texture_vie0;
   
  }
  
  else
  {
    delete t_texture_default;
  }
}


std::string Texture_engine::get_name()
{
  return name;
}

sf::Texture* Texture_engine::get_texture(int i)
{
  //return la bonne texture suivant le nom
  if (i == 0)
  return t_texture_default;
  
  else   if (i == 1)
  return t_texture_up;
  
  else   if (i == 2)
  return t_texture_down;
  
  else   if (i == 3)
  return t_texture_left;
  
  else   if (i == 4)
  return t_texture_right;
  
    else   if (i == 5)
  return t_texture_ico;
  
  else   if (i == 6)
  return t_texture_death;
  
    else   if (i == 7)
  return t_texture_vie3;
  
    else   if (i == 8)
  return t_texture_vie2;
  
    else   if (i == 9)
  return t_texture_vie1;
  
    else   if (i == 10)
  return t_texture_vie0;
  
  else
    return t_texture_default;
  

}

void Texture_engine::change_cont(int co)
{
   cont += co; //incrementation ou decrementation du conteur
}

int Texture_engine::get_cont()
{
  return cont; //retourne le conteur
}
