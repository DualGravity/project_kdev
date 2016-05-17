#ifndef WEAPONS_HPP_INCLUDED
#define WEAPONS_HPP_INCLUDED

#include "Initialisation.hpp"
#include "def.hpp"
#include "corps.hpp"

class Weapons : public Corps
{
	public:
	Weapons(b2Vec2 vec,float angle_weapons,G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_radius,float t_angledeg);
	~Weapons();
	void firstPini();
	float get_life_time();
	void set_death();
	void set_vaisseaux(int t_vaissseaux);
	int get_vaisseaux();
	
	protected:
        float m_radius,ax, ay,angle,gravfac;
	sf::Clock life_time_clock;
	bool mort;
	int vaisseaux;
};


#endif
