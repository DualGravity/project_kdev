#include "gravity_engine.hpp"

using namespace sf;

Gravity_engine::Gravity_engine()
{
}
Gravity_engine::~Gravity_engine()
{
}

void Gravity_engine::step(float dt,std::deque <Corps*> de_corps,std::deque <Planete*> de_planete,std::deque <Vaisseaux*> de_vaisseaux,std::deque <Weapons*> de_weapons)
{
    //POUR LES PLANETES
    for (int i=1; i < de_planete.size(); i++ )										//Boucle qui parcourt toutes les planetes
    {
        b2Vec2 planete1_position = de_planete.at(i)->Getp_body()->GetWorldCenter();	//planete1_position
	b2Vec2 velocity = de_planete.at(i)->Getp_body()->GetLinearVelocity();
	
	for (int j = 0; j < de_planete.size(); j++ )									//Boucle qui parcourt toutes les autres planetes
        {
            if (j!=i)
            {
	      b2Vec2 planete2_position = de_planete.at(j)->Getp_body()->GetWorldCenter();//planete2_position
	      b2Vec2 planet_distance (0,0);
              planet_distance = planete1_position - planete2_position;						// vector entre les 2 planetes
              
              
              double r = planet_distance.Length();
	      planet_distance.Normalize();
	      double force = (CONST_GRAVITATION * de_planete.at(j)->Getp_body()->GetMass() * de_planete.at(i)->Getp_body()->GetMass()) / (r*r);//Gravitation
	      
	      planet_distance.x = planet_distance.x * force;
              planet_distance.y = planet_distance.y * force;								//applique au vecteur la gravitation puis la rend attractive
	      planet_distance = -planet_distance;           								//
	      
	      de_planete.at(i)->Getp_body()->ApplyForce(planet_distance,de_planete.at(i)->Getp_body()->GetWorldCenter(),true);
	      //applique a la planete 1 la force suivant le veteur entre les 2 planetes
	      
            }
	}
      
    }

	//POUR LES VAISSEAUX
	for (int i=0; i < de_vaisseaux.size(); i++ )
    {
        b2Vec2 vaisseaux_position = de_vaisseaux.at(i)->Getp_body()->GetWorldCenter();
	
	b2Vec2 velocityv = de_vaisseaux.at(i)->Getp_body()->GetLinearVelocity();
	
	for (int j = 0; j < de_planete.size(); j++ )
        {
            b2Vec2 planet_position = de_planete.at(j)->Getp_body()->GetWorldCenter();
	    
            b2Vec2 between_distance (0,0);
            between_distance = vaisseaux_position - planet_position;
	    
	    double rp = between_distance.Length();
	    between_distance.Normalize();

	    double force = (CONST_GRAVITATION * de_vaisseaux.at(i)->Getp_body()->GetMass() * de_planete.at(j)->Getp_body()->GetMass()) / (rp*rp);

	    between_distance.x = between_distance.x * force;
	    between_distance.y = between_distance.y * force;
	    between_distance = -between_distance;

	    de_vaisseaux.at(i)->Getp_body()->ApplyForce(between_distance,de_vaisseaux.at(i)->Getp_body()->GetWorldCenter(),true);
	}
    }
    
    
    //POUR LES Arme
    for (int i=0; i < de_weapons.size(); i++ )
    {
        b2Vec2 _position = de_weapons.at(i)->Getp_body()->GetWorldCenter();

        for (int j = 0; j < de_planete.size(); j++ )
        {
            b2Vec2 planet_position = de_planete.at(j)->Getp_body()->GetWorldCenter();
	    
            b2Vec2 between_distance (0,0);
            between_distance = _position - planet_position;
	    
	    double rp = between_distance.Length();
	    between_distance.Normalize();

	    double force = (CONST_GRAVITATION * de_weapons.at(i)->Getp_body()->GetMass() * de_planete.at(j)->Getp_body()->GetMass()) / (rp*rp);

	    between_distance.x = between_distance.x * force;
	    between_distance.y = between_distance.y * force;
	    between_distance = -between_distance;

	    de_weapons.at(i)->Getp_body()->ApplyForce(between_distance,de_weapons.at(i)->Getp_body()->GetWorldCenter(),true);
	}
    }
    
        //pour les arme atirer par les vaisseaux
    for (int i=0; i < de_weapons.size(); i++ )
    {
        b2Vec2 _position = de_weapons.at(i)->Getp_body()->GetWorldCenter();
	
	 if (de_weapons.at(i)->get_vaisseaux() == 1)
	 {
	   b2Vec2 vaisseauxt_position = de_vaisseaux.at(1)->Getp_body()->GetWorldCenter();
	   b2Vec2 between_distance (0,0);
           between_distance = _position - vaisseauxt_position;
	   
	   double rp = between_distance.Normalize();
	   double force = (300 * de_weapons.at(i)->Getp_body()->GetMass() * de_vaisseaux.at(1)->Getp_body()->GetMass()) ;

	    between_distance.x = between_distance.x * force;
	    between_distance.y = between_distance.y * force;
	    between_distance = -between_distance;

	    de_weapons.at(i)->Getp_body()->ApplyForce(between_distance,de_weapons.at(i)->Getp_body()->GetWorldCenter(),true);
	}
	
	if (de_weapons.at(i)->get_vaisseaux() == 2)
	 {
	   b2Vec2 vaisseauxt_position = de_vaisseaux.at(0)->Getp_body()->GetWorldCenter();
	   b2Vec2 between_distance (0,0);
           between_distance = _position - vaisseauxt_position;
	   
	   double rp = between_distance.Normalize();
	   double force = (300 * de_weapons.at(i)->Getp_body()->GetMass() * de_vaisseaux.at(0)->Getp_body()->GetMass());

	    between_distance.x = between_distance.x * force;
	    between_distance.y = between_distance.y * force;
	    between_distance = -between_distance;

	    de_weapons.at(i)->Getp_body()->ApplyForce(between_distance,de_weapons.at(i)->Getp_body()->GetWorldCenter(),true);
	}
    }
}
