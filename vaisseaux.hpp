#ifndef VAISSEAUX_HPP_INCLUDED
#define VAISSEAUX_HPP_INCLUDED

#include "Initialisation.hpp"
#include "def.hpp"
#include "corps.hpp"

class Vaisseaux : public Corps
{
	public:
	Vaisseaux(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg,float t_puissance,float t_vitesserot);
      ~Vaisseaux();
	
	void actualise(float viewfact);
	void default_state();
	void turnLeft();
	void turnRight();
	void applyForce(float cmb);
	void set_mode(float mode);
	void kill();
	bool get_alive();


	protected:
	sf::Sprite *p_sprite_ico,*p_sprite_vie;
        float m_puissance;
        float m_vitesserot;
        float ax, ay;
        float angle;
	
	int nb_vie;
	
	bool alive;
};

#endif // VAISSEAUX_HPP_INCLUDED
