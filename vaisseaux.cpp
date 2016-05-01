#include "vaisseaux.hpp"

Vaisseaux::Vaisseaux(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_angledeg,
float t_puissance,float t_vitesserot) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg), m_puissance(t_puissance),m_vitesserot(t_vitesserot)
{
    p_dynamiquebody->SetAngularDamping(5);

    b2Vec2 mun;
	mun.x = 0;
    mun.y = 0;
    p_dynamiquebody->SetLinearVelocity(mun);
    
    p_sprite_ico = new sf::Sprite;
    p_sprite_ico = m_gen->create_sprite();
    p_sprite_ico->setTexture(*p_texture->get_texture(5));
    sf::Vector2u vec = p_sprite_ico->getTexture()->getSize();//veteur pour connaitre taille de la texture
    p_sprite_ico->setOrigin(vec.x/2,vec.y/2);   //orignie au milieu du sprite
    
}

Vaisseaux::~Vaisseaux()
{
    //appeler destruteur
}
void Vaisseaux::actualise(float viewfact)
{
    p_sprite->setPosition(p_dynamiquebody->GetPosition().x * SCALE,p_dynamiquebody->GetPosition().y * SCALE);
    p_sprite->setRotation(p_dynamiquebody->GetAngle() * 180/b2_pi);
    
    p_sprite_ico->setScale(viewfact/10000,viewfact/10000);
    p_sprite_ico->setPosition(p_dynamiquebody->GetPosition().x * SCALE,p_dynamiquebody->GetPosition().y * SCALE);
    p_sprite_ico->setRotation(p_dynamiquebody->GetAngle() * 180/b2_pi);
}

void Vaisseaux::default_state()
{
    p_sprite->setTexture(*p_texture->get_texture(0));
}

void Vaisseaux::applyForce(float cmb)
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
void Vaisseaux::turnLeft()
{
    p_dynamiquebody->ApplyAngularImpulse(-m_vitesserot,true);
    p_sprite->setTexture(*p_texture->get_texture(3));
}
void Vaisseaux::turnRight()
{
    p_dynamiquebody->ApplyAngularImpulse(m_vitesserot,true);
    p_sprite->setTexture(*p_texture->get_texture(4));
}



