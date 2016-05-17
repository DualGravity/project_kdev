#include "corps.hpp"

Corps::Corps(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg) :
m_density(t_density),m_friction(t_friction),m_restitution(t_restitution),m_px(t_px),m_py(t_py),m_tx(t_tx),m_ty(t_ty),m_world(t_world),m_gen(t_gen),m_angledeg(t_angledeg),name(t_name)
{
  
  p_texture = m_gen->create_texture(name);
  p_sprite = m_gen->create_sprite();
  p_sprite->setTexture(*p_texture->get_texture(0));
  
  sf::Vector2u vec = p_sprite->getTexture()->getSize();//veteur pour connaitre taille de la texture
  p_sprite->setOrigin(vec.x/2,vec.y/2);   //orignie au milieu du sprite
  p_sprite->setPosition(t_px,t_py);       //position du sprite
  p_sprite->setRotation(m_angledeg);         //rotation du sprite
  
  //Crée l'objet Box2d Dynamique
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(m_px/SCALE,m_py/SCALE);
  bodyDef.allowSleep = false;
  p_dynamiquebody = m_world->CreateBody(&bodyDef);
  b2PolygonShape shape;
  shape.SetAsBox(m_tx/2/SCALE,m_ty/2/SCALE);
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = m_density;
  fixtureDef.friction = m_friction;
  fixtureDef.restitution = m_restitution;
  p_dynamiquebody->CreateFixture(&fixtureDef);
  
  p_dynamiquebody->SetUserData(this);//pointeur vers soit dans les donnee utilisateur pour les collisions
}

Corps::~Corps()
{
   m_gen->delete_sprite(p_sprite);
   m_gen->delete_texture(name);
   m_world->DestroyBody(p_dynamiquebody);
}
void Corps::actualise() const
{
    p_sprite->setPosition(p_dynamiquebody->GetPosition().x * SCALE,p_dynamiquebody->GetPosition().y * SCALE);
    p_sprite->setRotation(p_dynamiquebody->GetAngle() * 180/b2_pi);
}

b2Body* Corps::Getp_body()
{
    return p_dynamiquebody;
}
float Corps::get_angle()
{
    return p_sprite->getRotation();
}

sf::Vector2f Corps::getVvec()
{
    return p_sprite->getPosition();
}

void Corps::set_linearspeed(b2Vec2 vec)
{
  p_dynamiquebody->SetLinearVelocity(vec);
}

std::string Corps::get_name()
{
  return name;
}
