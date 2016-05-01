#include "planete.hpp"


Planete::Planete(G_engine *t_gen,std::string t_name,b2World *t_world,float t_density,float t_friction,float t_restitution,float t_px,float t_py,float t_tx,float t_ty,float t_radius,float t_angledeg) :
Corps(t_gen,t_name,t_world,t_density,t_friction,t_restitution,t_px,t_py,t_tx,t_ty,t_angledeg),m_radius(t_radius)
{
    p_sprite->setOrigin(m_radius,m_radius);			//origine au centre de la planete

    b2Fixture *fixtureA = p_dynamiquebody->GetFixtureList();//demande la fixture du corp
    p_dynamiquebody->DestroyFixture(fixtureA);			//suprime afin de mettre une fixture Circle

    firstPini();										// initialisation planete avant de crée la fixture

    b2CircleShape pla;								//
    pla.m_radius = m_radius / SCALE;					//
    b2FixtureDef fixtureDef;							//
    fixtureDef.shape = &pla;							//		Creation fixture planete
    fixtureDef.density = m_density;						//
    fixtureDef.friction = m_friction;						//
    fixtureDef.restitution = m_restitution;					//
    p_dynamiquebody->CreateFixture(&fixtureDef);			//
    
}

Planete::~Planete()
{
    //appeler destruteur
}

float Planete::get_radius_gravitation()
{
    return (m_radius / SCALE * gravfac);
}

void Planete::firstPini() //Charge le G_fac  et la SCALE selon la planete
{
    if (name == SUN_TEXTURE)
	{
        gravfac = SUN_GRAVIVITYFAC;
        p_sprite->setScale(sf::Vector2f(SUN_SCALE,SUN_SCALE));
        m_radius = m_radius * SUN_SCALE;

	}

	else if (name == MOON_TEXTURE)
	{
        gravfac = MOON_GRAVIVITYFAC;
        p_sprite->setScale(sf::Vector2f(MOON_SCALE,MOON_SCALE));
        m_radius = m_radius * MOON_SCALE;

	}
	
	else if (name == MERCURE_TEXTURE)
	{
        gravfac = MERCURE_GRAVIVITYFAC;
        p_sprite->setScale(sf::Vector2f(MERCURE_SCALE,MERCURE_SCALE));
        m_radius = m_radius * MERCURE_SCALE;

	}
}

void Planete::secondPini()
{
    if (name == SUN_TEXTURE)
	{
        b2Vec2 mun;
        mun.x = 0;
        mun.y = 0;
        //p_dynamiquebody->SetLinearVelocity(mun);
        p_dynamiquebody->ApplyForce(mun,p_dynamiquebody->GetWorldCenter(),true);

	}

	else if (name == MOON_TEXTURE)
	{
        b2Vec2 mun;
        mun.x = 0;
        mun.y = 0;
        //p_dynamiquebody->SetLinearVelocity(mun);
        p_dynamiquebody->ApplyForce(mun,p_dynamiquebody->GetWorldCenter(),true);

	}
	
	else if (name == MERCURE_TEXTURE)
	{
        b2Vec2 mercure;
        mercure.x = 0;
        mercure.y = 10000;
        p_dynamiquebody->SetLinearVelocity(mercure);
        //p_dynamiquebody->ApplyForce(mercure,p_dynamiquebody->GetWorldCenter(),true);

	}

}
