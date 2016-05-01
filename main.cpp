#include "Initialisation.hpp"

#include "vaisseaux.hpp"
#include "worldengine.hpp"
#include "corps.hpp"
#include "g_engine.hpp"
#include "corpsfix.hpp"
#include "event_engine.hpp"


using namespace std;
using namespace sf;

int main()
{


    // Create the main window
    RenderWindow app(VideoMode(1600,900), "Duel Gravity",sf::Style::Close);
    //app.setFramerateLimit(60);
    
    sf::Image icon;
 
    icon.loadFromFile("Image/ico.png");
    app.setIcon(32,32,icon.getPixelsPtr());

    //World Box2d proprety
    b2Vec2 gravity(0.0f,0.0f);
    b2World worldBox2d(gravity);

    //World engine
    Worldengine world01(&app,&worldBox2d);

    //Creation class Event_engine event_engine
    Event_engine event_engine(&app,&world01);

    /*Creation class Networks_engine networks_engine
    Event_engine event_engine(&app);*/

    //Clock1
    sf::Clock clock1;
    float dt;//delta de temps

    //Reine des Neiges morray
    sf::Music music;
    music.openFromFile("Neige.wav");
    
    // Start the game loop
    while (app.isOpen())
    {
        event_engine.step();
        if (sf::Keyboard::isKeyPressed(Keyboard::R))
        music.play();
	
	if (sf::Keyboard::isKeyPressed(Keyboard::Escape))
        app.close();

        //gestion du dt
        sf::Time elapsed1 = clock1.restart();//redemmare et prend la valeur du temp ecoulée
        dt = elapsed1.asSeconds();           	//temps en seconde

        world01.step(dt);
      
	
    }
    
    return EXIT_SUCCESS;
}


