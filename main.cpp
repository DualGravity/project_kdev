/*	***********************************************************************************************************************************************
 * Duel gravity 
 * 	***********************************************************************************************************************************************	*/

#include "Initialisation.hpp"
#include "def.hpp"

#include "vaisseaux.hpp"
#include "worldengine.hpp"
#include "corps.hpp"
#include "g_engine.hpp"
#include "corpsfix.hpp"
#include "event_engine.hpp"

 #include "menu.cpp"

using namespace std;
using namespace sf;

int main()
{
  
  while (stepm() == 0)	{}//temp que l'on dans le menu on y reste
  if (stepm() != 2)	// si menu renvoi que le jeu doit etre executé :
  {
    // Create the main window
    RenderWindow app(VideoMode(1600,900), "Duel Gravity",sf::Style::Close);
    
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
    
    /* sf::Music music;
      if (!music.openFromFile("Audio/theme.ogg"))
	  return -1; // erreur
      music.play();
      music.setVolume(20);*/
      
    // Start the game loop
    while (app.isOpen())	//tenps que fenetre ouverte :
    {
	//gestion du dt
	sf::Time elapsed1 = clock1.restart();	//redemmare et prend la valeur du temp ecoulée
	dt = elapsed1.asSeconds();			//temps en seconde

	world01.step(dt);					//actualisation du monde ou on lui envoi le delta de temps ecoulée entre 2 actualisation
	event_engine.step();					//lit les evenenment 
    }
    
   }
  
  return EXIT_SUCCESS;
}


