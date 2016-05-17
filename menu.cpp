#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>



sf::RenderWindow window;

sf::Vector2i positionSouris = sf::Mouse::getPosition(window);
sf::Texture menu;
sf::Texture start;
sf::Texture mexit;
sf::Sprite s_menu;

int gestion_souris();
int stepm ();

int stepm ()
{
	window.create(sf::VideoMode(1200,600), "SFML",sf::Style::Default);
	window.setFramerateLimit(60);



	if (!menu.loadFromFile("Image/menu.png"))
	{
		std::cout << "Erreur chargement menu.png" << std::endl;
	}
	start.loadFromFile("Image/play_s.png");
	mexit.loadFromFile("Image/exit_s.png");

	s_menu.setTexture(menu);
	menu.setSmooth(true);

	while (gestion_souris() == 0)	// reste dans la boucle si on doit etre dans le menu
	{

		positionSouris = sf::Mouse::getPosition(window);
	
		window.draw(s_menu);
		window.display();
		window.clear();
		
	}
	
	if(gestion_souris() == 2)	//si on doit fermé
	  window.close();

	return gestion_souris();//informe le main de la situation
}

int gestion_souris() 
{
	if (positionSouris.x >= 460  && positionSouris.x <= 710 && positionSouris.y >= 290 && positionSouris.y <= 380)
	{ 
		s_menu.setTexture(start);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
		  window.close();
		  return 1;
		}
		return 0;
	}
	else if (positionSouris.x >= 460 && positionSouris.x <= 710 && positionSouris.y >= 420 && positionSouris.y <= 510)
	{
		s_menu.setTexture(mexit);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{ 
			return 2;
		}
		return 0;
			
	}
	else
	{
		s_menu.setTexture(menu);
		
	}
	return 0;
}
