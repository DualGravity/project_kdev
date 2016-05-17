#ifndef PLANETE_HPP_INCLUDED
#define PLANETE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "def.hpp"
#include "corps.hpp"

class Planete : public Corps
{
	public:
	Planete(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_radius,float t_angledeg);
    ~Planete();

	void applyForce(float cmb);
	void step(int pdt);
	float get_radius_gravitation();
	void firstPini();
	void secondPini();
	protected:
        float m_radius,ax, ay,angle,gravfac;

};


#endif // PLANETE_HPP_INCLUDED
