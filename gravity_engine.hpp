#ifndef GRAVITY_ENGINE_HPP_INCLUDED
#define GRAVITY_ENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "corps.hpp"
#include "vaisseaux.hpp"
#include "planete.hpp"
#include "weapons.hpp"


class Gravity_engine
{
	public:
	Gravity_engine();
	~Gravity_engine();
	
	void step(float dt,std::deque <Corps*> de_corps,std::deque <Planete*> de_planete,std::deque <Vaisseaux*> de_vaisseaux,std::deque <Weapons*> de_weapons);

	protected:
};

#endif // GRAVITY_ENGINE_HPP_INCLUDED
