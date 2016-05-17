#include "vaisseaux.hpp"

Vaisseaux::Vaisseaux(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg,
float t_puissance,float t_vitesserot) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg), m_puissance(t_puissance),m_vitesserot(t_vitesserot)
{
  
  nb_vie = 3;
  
  
    alive = true;
    p_dynamiquebody->SetAngularDamping(10);
    
    p_sprite_ico = m_gen->create_sprite();
    p_sprite_ico->setTexture(*p_texture->get_texture(5));
    sf::Vector2u vec = p_sprite_ico->getTexture()->getSize();//veteur pour connaitre taille de la texture
    p_sprite_ico->setOrigin(vec.x/2,vec.y/2);   //orignie au milieu du sprite
 
    p_sprite_vie = m_gen->create_sprite();
    p_sprite_vie->setTexture(*p_texture->get_texture(7));
    sf::Vector2u vec_vie = p_sprite_vie->getTexture()->getSize();//veteur pour connaitre taille de la texture
    p_sprite_vie->setOrigin(vec_vie.x/2,vec_vie.y/2);   //orignie au milieu du sprite
}

Vaisseaux::~Vaisseaux()
{
  
}
void Vaisseaux::actualise(float viewfact)
{
    p_sprite->setPosition(p_dynamiquebody->GetPosition().x * SCALE,p_dynamiquebody->GetPosition().y * SCALE);
    p_sprite->setRotation(p_dynamiquebody->GetAngle() * 180/b2_pi);

    
    p_sprite_ico->setScale(viewfact/10000,viewfact/10000);
    p_sprite_ico->setPosition(p_dynamiquebody->GetPosition().x * SCALE,p_dynamiquebody->GetPosition().y * SCALE);
    p_sprite_ico->setRotation(p_dynamiquebody->GetAngle() * 180/b2_pi);
    
    p_sprite_vie->setScale(viewfact/10000,viewfact/10000);
    p_sprite_vie->setPosition(((p_dynamiquebody->GetPosition().x )* SCALE) + (300 *viewfact/10000),p_dynamiquebody->GetPosition().y * SCALE);
    
  
  if (nb_vie == 2)
  {
        p_sprite_vie->setTexture(*p_texture->get_texture(8));
  }
  else  if (nb_vie == 1)
  {
        p_sprite_vie->setTexture(*p_texture->get_texture(9));
  }
  if ( alive == false)
  {
    p_sprite_vie->setPosition(1000000000,p_dynamiquebody->GetPosition().y * SCALE);
    
        p_sprite_ico->setScale(viewfact/8000,viewfact/8000);
    
  }

}

void Vaisseaux::default_state()
{
  if (alive == true)
  {
    p_sprite->setTexture(*p_texture->get_texture(0));
  }
    
}
void Vaisseaux::applyForce(float cmb)
{
  if (alive == true)
  {
    b2Vec2 vec;
    vec.x = cos(p_dynamiquebody->GetAngle()-(M_PI/2)) * m_puissance * cmb;
    vec.y = sin(p_dynamiquebody->GetAngle()-(M_PI/2)) * m_puissance * cmb;
    p_dynamiquebody->ApplyLinearImpulse(vec,p_dynamiquebody->GetWorldCenter(),true);
    
      if (cmb > 0)
      {
	p_sprite->setTexture(*p_texture->get_texture(1));
      }
      
      else if (cmb < 0)
      {
	p_sprite->setTexture(*p_texture->get_texture(2));
      }
  } 
}
void Vaisseaux::turnLeft()
{
  if (alive == true)
  {
    p_dynamiquebody->ApplyAngularImpulse(-m_vitesserot,true);
    p_sprite->setTexture(*p_texture->get_texture(3));
  }
}
void Vaisseaux::turnRight()
{
  if (alive == true)
  {
    p_dynamiquebody->ApplyAngularImpulse(m_vitesserot,true);
    p_sprite->setTexture(*p_texture->get_texture(4));
  }
}

void Vaisseaux::set_mode(float mode)
{
    m_puissance =  mode;
}

void Vaisseaux::kill()
{
    nb_vie--;
    if (nb_vie == 0)
    {
    p_sprite_ico->setTexture(*p_texture->get_texture(10));
    
    alive = false;
    }
}
    
bool Vaisseaux::get_alive()
{
  return alive;
}

