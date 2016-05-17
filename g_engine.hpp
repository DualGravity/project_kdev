#ifndef G_ENGINE_HPP_INCLUDED
#define G_ENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "texture_engine.hpp"

class G_engine
{
	public:
	G_engine(sf::RenderWindow *t_app);
	~G_engine();
	void affiche_sprites(int nb_objet,float t_pps);
	Texture_engine* create_texture(std::string name);
	sf::Sprite* create_sprite();
	void  delete_sprite(sf::Sprite *p_sprite);
	void Changeview(float factor,sf::Vector2f t_vec,float factor2,sf::Vector2f t_vec2);
	sf::Texture* texture_load(std::string name);			//Chargement texture
	void  delete_texture(std::string name);			//Destruction texture
	std::string  affiche_Texte(sf::Vector2f t_vec);
	float get_viewfactor();
	float get_viewfactor2();
	
	protected:
	sf::RenderWindow *p_app;
	sf::Clock clock;
	sf::Clock clock_global;
	sf::Text text,text2;
	sf::Font font;
	sf::Vector2f g_vec,g_vec2;
	std::deque <sf::Sprite*> de_sprite;
	std::deque <Texture_engine*> de_texture;
	sf::View *p_view,*p_player1View,*p_player2View;
	float view_factor,view_factor2,pps;
	int nb_ob;
};

#endif // G_ENGINE_HPP_INCLUDED


// 