
#include "corpsfix.hpp"

Corpsfix::Corpsfix(G_engine *t_gen,std::string name,b2World *t_world,float t_px, float t_py, float t_tx,float t_ty,float t_angledeg) :
m_px(t_px),m_py(t_py),m_tx(t_tx),m_ty(t_ty),m_world(t_world),m_gen(t_gen),m_angledeg(t_angledeg)
{
    //crée et place le sprite dans le G_engine et recupére le pointer vers le son sprite
    p_sprite = m_gen->create_sprite();
    //p_sprite->setRotation(45);
    //p_sprite->getTextureRect()

    //Crée l'objet Box2d
    b2BodyDef groundBodyDef2;
    groundBodyDef2.position.Set(m_px/SCALE,m_py/SCALE);
    m_groundBody2 = m_world->CreateBody(&groundBodyDef2);
    b2PolygonShape groundBox2;
    groundBox2.SetAsBox((m_tx/2)/SCALE,(m_ty/2)/SCALE);
    m_groundBody2->CreateFixture(&groundBox2, 0.0f);
}

Corpsfix::~Corpsfix()
{
    //detruire plein de trucs
}
