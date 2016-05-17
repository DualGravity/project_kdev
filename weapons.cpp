#include "weapons.hpp"


Weapons::Weapons(b2Vec2 vec,float angle_weapons,G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_radius,float t_angledeg) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg),m_radius(t_radius)
{
  
  vaisseaux = 0;
  mort = false;
  life_time_clock.restart();
  p_sprite->setOrigin(m_radius,m_radius);			//origine au centre de la planete
  
  p_sprite->setScale(sf::Vector2f(WEAPONS01_SCALE,WEAPONS01_SCALE));
  m_radius = m_radius * WEAPONS01_SCALE;

  b2Fixture *fixtureA = p_dynamiquebody->GetFixtureList();//demande la fixture du corp
  p_dynamiquebody->DestroyFixture(fixtureA);			//suprime afin de mettre une fixture Circle
  b2CircleShape pla;								//
  pla.m_radius = m_radius / SCALE;					//
  b2FixtureDef fixtureDef;							//
  fixtureDef.shape = &pla;							//		Creation fixture Arme
  fixtureDef.density = m_density;						//
  fixtureDef.friction = m_friction;						//
  fixtureDef.restitution = m_restitution;					//
  p_dynamiquebody->CreateFixture(&fixtureDef);			//

  vec.x	+= cos((angle_weapons - 90 ) * M_PI / 180.0) * 500;
  vec.y	+= sin((angle_weapons - 90) * M_PI / 180.0) * 500;
  
  p_dynamiquebody->SetLinearVelocity(vec);
  

}

Weapons::~Weapons()
{
}
float Weapons::get_life_time()
{
  if (mort == false)
  {
    sf::Time life_time = life_time_clock.getElapsedTime();
  return life_time.asSeconds();
    
  }
  return 10000.f;
  
}
void Weapons::set_death()
{
  mort = true;
}
void Weapons::set_vaisseaux(int t_vaissseaux)
{
  vaisseaux = t_vaissseaux;
}

int Weapons::get_vaisseaux()
{
  return vaisseaux;
}
