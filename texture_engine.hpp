#ifndef TEXTURE_ENGINE_HPP_INCLUDED
#define TEXTURE_ENGINE_INCLUDED

#include "Initialisation.hpp"

class Texture_engine
{
	public:
	Texture_engine(std::string t_name);
	~Texture_engine();
	std::string get_name();
	sf::Texture* get_texture(int i);
	void change_cont(int co);
	int get_cont();
	

	protected:
	  int cont;
	  
	  sf::Texture* t_texture_default;
	  
	  sf::Texture* t_texture_up;
	  sf::Texture*  t_texture_down;
	  sf::Texture* t_texture_left;
	  sf::Texture* t_texture_right;
	  
	  sf::Texture* t_texture_ico;
	  
	  std::string name;
        


};

#endif // TEXTURE_ENGINE_INCLUDED

