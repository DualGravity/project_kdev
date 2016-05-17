#include"event_engine.hpp"

using namespace sf;

Event_engine::Event_engine(sf::RenderWindow *t_app,Worldengine *t_world) :
p_app(t_app),p_world(t_world)
{
}
Event_engine::~Event_engine()
{
}

bool Event_engine::step()
{
        // Process events    
	if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
	{
// 	  p_world->~Worldengine();
	  p_app->close();
	}
        //Gestion du zoom
        if (sf::Keyboard::isKeyPressed(Keyboard::T))
            p_world->changeview(0,0.998f,0);

        if (sf::Keyboard::isKeyPressed(Keyboard::Y))
            p_world->changeview(0,1.002f,0);
	
	if (sf::Keyboard::isKeyPressed(Keyboard::Numpad2))
            p_world->changeview(0,0,0.998f);

	if (sf::Keyboard::isKeyPressed(Keyboard::Numpad3))
            p_world->changeview(0,0,1.002f);

        //Gestion du DEPLACEMENT
        if (sf::Keyboard::isKeyPressed(Keyboard::D))
            p_world->controlV1(6);
        else if (sf::Keyboard::isKeyPressed(Keyboard::Q))
            p_world->controlV1(4);
        else if (sf::Keyboard::isKeyPressed(Keyboard::Z))
            p_world->controlV1(8);
        else if (sf::Keyboard::isKeyPressed(Keyboard::S))
            p_world->controlV1(5);
	else{  p_world->controlV1(0); }
	
	
	
	
	//Gestion du mode
        if (sf::Keyboard::isKeyPressed(Keyboard::G))
            p_world->controlV1_mode(0.02);
       if (sf::Keyboard::isKeyPressed(Keyboard::H))
            p_world->controlV1_mode(0.06);
       if (sf::Keyboard::isKeyPressed(Keyboard::J))
            p_world->controlV1_mode(0.1);
       if (sf::Keyboard::isKeyPressed(Keyboard::K))
            p_world->controlV1_mode(1);
       

        //Gestion du DEPLACEMENT           
        if (sf::Keyboard::isKeyPressed(Keyboard::Right))
            p_world->controlV2(6);
        else if (sf::Keyboard::isKeyPressed(Keyboard::Left))
            p_world->controlV2(4);
        else if (sf::Keyboard::isKeyPressed(Keyboard::Up))
            p_world->controlV2(8);
        else if (sf::Keyboard::isKeyPressed(Keyboard::Down))
            p_world->controlV2(5);
	else {  p_world->controlV2(0); }
	
	
	if (sf::Keyboard::isKeyPressed(Keyboard::Numpad0))
            p_world->V2_fire();
	
	if (sf::Keyboard::isKeyPressed(Keyboard::A))
            p_world->V1_fire();
	
	
	//Gestion de la vue
        if (sf::Keyboard::isKeyPressed(Keyboard::F1))
             p_world->changeview(1,0,0);
        else if (sf::Keyboard::isKeyPressed(Keyboard::F2))
             p_world->changeview(2,0,0);
        else if (sf::Keyboard::isKeyPressed(Keyboard::F3))
             p_world->changeview(3,0,0);
        else if (sf::Keyboard::isKeyPressed(Keyboard::F4))
             p_world->changeview(4,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F5))
	    p_world->changeview(5,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F6))
	    p_world->changeview(6,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F7))
	    p_world->changeview(7,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F8))
	    p_world->changeview(8,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F9))
	    p_world->changeview(9,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F10))
	    p_world->changeview(10,0,0);
	else if (sf::Keyboard::isKeyPressed(Keyboard::F11))
	    p_world->changeview(11,0,0);
	
	if (sf::Keyboard::isKeyPressed(Keyboard::Space))
            p_world->change_traine();
}
