#ifndef EVENT_ENGINE_HPP_INCLUDED
#define EVENT_ENGINE_HPP_INCLUDED


#include "Initialisation.hpp"
#include "worldengine.hpp"

class Event_engine
{
	public:
	Event_engine(sf::RenderWindow *t_app,Worldengine *t_world);
	~Event_engine();
	void step();

	protected:
	sf::RenderWindow *p_app;
	Worldengine *p_world;

};

#endif // EVENT_ENGINE_HPP_INCLUDED
