#ifndef CORPSFIX_HPP_INCLUDED
#define CORPSFIX_HPP_INCLUDED

#include "Initialisation.hpp"
#include "g_engine.hpp"

class Corpsfix
{
	public:
	Corpsfix(G_engine *t_gen,std::string name,b2World *t_world,float t_px, float t_py, float t_tx,float t_ty,float t_angledeg);

	~Corpsfix();

	protected:
	G_engine *m_gen;                            //pointer vers le G engine
	b2World *m_world;                           //pointer vers le World Box2d
	b2Body *m_groundBody2;                      //pointer vers l'objet dans Box2d
	float m_px, m_py, m_tx, m_ty,m_angledeg;    //variable propre au Corps
	sf::Sprite *p_sprite;                       //pointer vers le sprite du corps
	std::string name;                           //nom du fichier a charger pour le sprite

};



#endif // CORPSFIX_HPP_INCLUDED
