#ifndef WORLDENGINE_HPP_INCLUDED
#define WORLDENGINE_HPP_INCLUDED

#include "Initialisation.hpp"
#include "def.hpp"

#include "collision_engine.hpp"


#include "gravity_engine.hpp"
#include "vaisseaux.hpp"
#include "corps.hpp"
#include "g_engine.hpp"
#include "corpsfix.hpp"
#include "planete.hpp"
#include "weapons.hpp"





class Worldengine
{
	public:
	Worldengine(sf::RenderWindow *t_app,b2World *t_world);
	~Worldengine();

	void step(float dt);
	void changeview(int vu,float factor,float factor2);	//change l'echelle de vu est la valeur de view
	void chargevec_view(int vu);					//charge les differente vu (vaisseaux1 ,2 ,Soleil,Terre,Lune...)
	void controlV1_mode(float mode);				//Change coef de puissance des moteur du Vaisseaux 1
	void controlV1(float nb);						//Gestion du deplacement (tourne gauch,droite marche avant/arriere) de Vu Vaisseaux 1
	void controlV2(float nb);						//Gestion du deplacement (tourne gauch,droite marche avant/arriere) de Vu Vaisseaux 2
	void lanceplanete();							//Donne une vitesse initiale au planetes pour leurs orbites
	void V1_fire();									//Lance un projectile pour v1
	void V2_fire();									//Lance un projectile pour v2
	void change_traine();							//Active / Desactive la trainer des objet dans le monde (permet de montré les orbits)
	int get_world_nb_corps();						//Retourne les nombre total de corps present dans world
	void remove_weapons();						//Suprime les projectiles qui sont en fin de vie

	protected:
	sf::RenderWindow *p_app;															//pointeur vers la fenetre SFML
	sf::Clock clock_rate_fire,clock_rate_fire2,clock_rate_touche,clock_gravstep,clock_display;	//Differente horloge
	G_engine *p_gengine;																//Le Graphique engine
	b2World *p_world;																	//Le monde BOX2D
	std::deque <Corpsfix*> de_corpsfix;													//Liste des Corps fixe
	std::deque <Corps*> de_corps;														//Liste des Corps
	std::deque <Vaisseaux*> de_vaisseaux;												//Liste des Vaisseaux
	std::deque <Planete*> de_planete;													//Liste des Planete
	std::deque <Weapons*>  de_weapons;													//Liste des Weapons

	Gravity_engine grav;																//La Gestion de La Gravitation
	float view_factor,view_factor2;														//Pour connaitre le zoom de l'affichage
	Collision_engine *p_coleng;															//Collision engine
	sf::Vector2f p_vec_view;																//vecteur de position de la vie
	int view;																			//n° de la vu
	bool e_clear;																		//affiche ou pas la trainer des corps

};


#endif // WORLDENGINE_HPP_INCLUDED

