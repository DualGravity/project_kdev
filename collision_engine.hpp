#ifndef COLLISION_ENGINE_HPP_INCLUDED
#define COLLISION_ENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "def.hpp"
#include "corps.hpp"
#include "vaisseaux.hpp"
#include "weapons.hpp"

class Collision_engine : public b2ContactListener
{
	public:
	Collision_engine();	//Constructeur
	~Collision_engine();				//Destructeur
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);

	

	protected:

};

#endif 

