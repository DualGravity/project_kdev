#ifndef VAISSEAUX_HPP_INCLUDED
#define VAISSEAUX_HPP_INCLUDED

#include "Initialisation.hpp"
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


	protected:
	sf::Sprite *p_sprite_ico;
        float m_puissance;
        float m_vitesserot;
        float ax, ay;
        float angle;
};

#endif // VAISSEAUX_HPP_INCLUDED
