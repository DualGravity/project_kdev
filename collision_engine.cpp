#include "collision_engine.hpp"


Collision_engine::Collision_engine()
{
}

Collision_engine::~Collision_engine()
{
  
}
void Collision_engine::BeginContact(b2Contact* contact) 
{
  
  void  *bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
  
  if (static_cast<Corps*>( bodyUserData )->get_name() == "vaisseaux")
  {
    static_cast<Vaisseaux*>( bodyUserData )->kill();
  }
  
    void  *bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( static_cast<Corps*>( bodyUserDataB )->get_name() == "vaisseaux")
  {
    static_cast<Vaisseaux*>( bodyUserDataB )->kill();
  }
  
    if (static_cast<Corps*>( bodyUserData )->get_name() == WEAPONS01_TEXTURE)
  {
    static_cast<Weapons*>( bodyUserData )->set_death();
  }
  
    if ( static_cast<Corps*>( bodyUserDataB )->get_name() == WEAPONS01_TEXTURE)
  {
    static_cast<Weapons*>( bodyUserDataB )->set_death();
  }
  
  
    

}
  
void Collision_engine::EndContact(b2Contact* contact) 
{
  
}

