#ifndef CORPS_HPP_INCLUDED
#define CORPS_HPP_INCLUDED



/* Class Corps
 * 
 * Class mere de Vaisseaux et de Planete qui possede son objet Box2d,son sa Texture et le sprite SFML
 * 
 * Cette Class demand un pointeur d'un objet g_engine, un monde Box2d ainsi que de multiples donnée sur les caracteristiques du corps
 * 
 * 
 * 
*/

#include "Initialisation.hpp"
#include "def.hpp"
#include "g_engine.hpp"

class Corps
{
	public:
	Corps(G_engine *t_gen,std::string name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_ty,float t_tx,float t_angledeg);
	~Corps();

	void actualise() const;
	b2Body* Getp_body();
	sf::Vector2f getVvec();
	void set_linearspeed(b2Vec2 vec);
	float get_angle();
	std::string get_name();

	protected:
	G_engine *m_gen;                            //pointer vers le G engine
	b2World *m_world;                           //pointer vers le World Box2d
	b2Body *p_dynamiquebody;                    //pointer vers l'objet dans Box2d Dynamique
	float m_px, m_py,m_angledeg,                //variable propre au Corps
	m_density,m_friction,m_restitution,m_tx, m_ty;
	
	std::string name;                           //nom du fichier a charger pour le sprite
	sf::Sprite *p_sprite;
	Texture_engine  *p_texture;
};

#endif // CORPS_HPP_INCLUDED
