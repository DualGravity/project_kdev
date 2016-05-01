#include "texture_engine.hpp"

Texture_engine::Texture_engine(std::string t_name)
{
  name = t_name;
  cont = 1;
  
  if (name == "vaisseaux")
  {
    t_texture_default = new sf::Texture;
    t_texture_up = new sf::Texture;
    t_texture_down = new sf::Texture;
    t_texture_left = new sf::Texture;
    t_texture_right = new sf::Texture;
    t_texture_ico = new sf::Texture;
    
    t_texture_default->loadFromFile("Image/vai.bmp");
    t_texture_up->loadFromFile("Image/vaimaa.bmp");
    t_texture_down->loadFromFile("Image/vaimar.bmp");
    t_texture_left->loadFromFile("Image/vaig.bmp");
    t_texture_right->loadFromFile("Image/vaid.bmp");
    t_texture_ico->loadFromFile("Image/vai_ico2.bmp");
    
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
  
   else
  {
    t_texture_default = new sf::Texture;
    t_texture_default->loadFromFile("Image/cb.bmp");
  }
  

}
Texture_engine::~Texture_engine()
{
   if (name == "vaisseaux")
  {
   delete  t_texture_default;
   delete  t_texture_up;
   delete  t_texture_down;
   delete  t_texture_left;
   delete t_texture_right;
   delete t_texture_ico;
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
  
  else
    return t_texture_default;
  

}

void Texture_engine::change_cont(int co)
{
  cont = cont + co;
}

int Texture_engine::get_cont()
{
  return cont;
}
