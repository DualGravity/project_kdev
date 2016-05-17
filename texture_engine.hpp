#ifndef TEXTURE_ENGINE_HPP_INCLUDED
#define TEXTURE_ENGINE_INCLUDED

/* Class Texture_engine : elle s'ocuppe de la gestion des Textures SFML.
 * La creation de cette class est precisement pour de l'optimisation memoire.
 * Cad quelle evite que a chaque texture cree qui existe deja l'on en recharge une nouvelle.
 * Le concept c'est que quand une texture n'est pas encore cree, on en cree une nouvelle auquelle on associe 
 * un conteur qui s'initialise a 1
 * L'orsque qui nouvelle texture demande a etre cree l'on demande si elle existe deja et sinon soit on la cree soit on incremente le conteur
 * la destruction de la Texture fonctionne sur le meme principe
 */

#include "Initialisation.hpp"
#include "def.hpp"

class Texture_engine
{
	public:
	Texture_engine(std::string t_name);	//Constructeur demande le nom de la texture a cree
	~Texture_engine();				//Destructeur
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
	   sf::Texture* t_texture_death,*t_texture_vie3,*t_texture_vie2,*t_texture_vie1,*t_texture_vie0;
	   
	  
	  sf::Texture* t_texture_ico;
	  
	  std::string name;
        


};

#endif // TEXTURE_ENGINE_INCLUDED

