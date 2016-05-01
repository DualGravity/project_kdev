#ifndef WORLDENGINE_HPP_INCLUDED
#define WORLDENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "gravity_engine.hpp"
#include "vaisseaux.hpp"
#include "corps.hpp"
#include "g_engine.hpp"
#include "corpsfix.hpp"
#include "planete.hpp"


class Worldengine
{
	public:
	Worldengine(sf::RenderWindow *t_app,b2World *t_world);
	~Worldengine();

	void step(float dt);
	void changeview(float factor);
	void controlV1(float nb);
	void controlV2(float nb);
	void lanceplanete();

	protected:
	sf::RenderWindow *p_app;
	sf::Clock clock_ini_planete;
	sf::Clock clock_gravstep;
	sf::Clock clock_display;
	G_engine *p_gengine;
	b2World *p_world;
	std::deque <Corpsfix*> de_corpsfix;
	std::deque <Corps*> de_corps;
	std::deque <Vaisseaux*> de_vaisseaux;
	std::deque <Planete*> de_planete;
	Gravity_engine grav;
	float view_factor;

};


#endif // WORLDENGINE_HPP_INCLUDED

