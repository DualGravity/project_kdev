#ifndef G_ENGINE_HPP_INCLUDED
#define G_ENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "texture_engine.hpp"

class G_engine
{
	public:
	G_engine(sf::RenderWindow *t_app);
	~G_engine();
	void affiche_sprites();
	Texture_engine* create_texture(std::string name);
	sf::Sprite* create_sprite();
	void Changeview(float factor,sf::Vector2f t_vec);
	sf::Texture* texture_load(std::string name);
	void  delete_texture(std::string name);
	void affiche_Texte();
	float get_viewfactor();

	protected:
	sf::RenderWindow *p_app;
	sf::Clock clock;
	sf::Text text;
	sf::Font font;
	sf::Vector2f g_vec;
	std::deque <sf::Sprite*> de_sprite;
	std::deque <Texture_engine*> de_texture;
	sf::View *p_view;
	float view_factor;
	
	
	
	

	//std::deque <Texture_engine*> de_texture;
	//std::map<std::string, stru_texture> de_texture;

};

#endif // G_ENGINE_HPP_INCLUDED


