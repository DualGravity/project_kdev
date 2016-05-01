#include "gravity_engine.hpp"

using namespace sf;

Gravity_engine::Gravity_engine()
{
}
Gravity_engine::~Gravity_engine()
{
}

void Gravity_engine::step(float dt,std::deque <Corps*> de_corps,std::deque <Planete*> de_planete,std::deque <Vaisseaux*> de_vaisseaux)
{
    //POUR LES PLANETE
    for (int i=0; i < de_planete.size(); i++ )
    {
        b2Vec2 planete1_position = de_planete.at(i)->Getp_body()->GetWorldCenter();//planete1_position
	
	
	b2Vec2 velocity = de_planete.at(i)->Getp_body()->GetLinearVelocity();
	
	velocity .operator*=(dt * 0.5);
	
	planete1_position = planete1_position + velocity;
	
	/*planete1_position.x +=  de_planete.at(i)->Getp_body()->GetLinearVelocity().x * dt * 0.5;
	planete1_position.y +=  de_planete.at(i)->Getp_body()->GetLinearVelocity().y * dt * 0.5;*/

        for (int j = 0; j < de_planete.size(); j++ )
        {
            if (j!=i)
            {
                b2Vec2 planete2_position = de_planete.at(j)->Getp_body()->GetWorldCenter();//planete2_position

                b2Vec2 planet_distance (0,0);
                planet_distance = planete1_position - planete2_position;// vector between the planete.

                if (planet_distance.Length() < de_planete.at(j)->get_radius_gravitation())
                {
                    float force = (CONST_GRAVITATION * de_planete.at(j)->Getp_body()->GetMass() * de_planete.at(i)->Getp_body()->GetMass()) / pow(planet_distance.Length(), 2);//Gravitation
                    planet_distance.x = planet_distance.x * force;//
                    planet_distance.y = planet_distance.y * force;//applique au vecteur la gravitation puis la rend attractive
                    planet_distance = -planet_distance;           //

                    de_planete.at(i)->Getp_body()->ApplyForce(planet_distance,de_planete.at(i)->Getp_body()->GetWorldCenter(),true);//applique a la planete 1
		  
                }
            }
	}
		// Draw linear velocity for the debris
		/*ctx.save();
		ctx.strokeStyle = 'rgba(255,0,0,1)';
		ctx.lineWidth = 1;

		ctx.beginPath();
		var linear_velocity = debris[i].GetLinearVelocity();
		ctx.moveTo(b2p(debris_position.x), b2p(debris_position.y));
		ctx.lineTo(b2p(debris_position.x) + b2p(linear_velocity.x),
				   b2p(debris_position.y) + b2p(linear_velocity.y));
		ctx.stroke();

		ctx.fill();
		ctx.restore();*/
	}

	//POUR LES VAISSEAUX
	for (int i=0; i < de_vaisseaux.size(); i++ )
    {
        b2Vec2 vaisseaux_position = de_vaisseaux.at(i)->Getp_body()->GetWorldCenter();
	
	
	b2Vec2 velocityv = de_vaisseaux.at(i)->Getp_body()->GetLinearVelocity();
	
	vaisseaux_position.x +=  de_vaisseaux.at(i)->Getp_body()->GetLinearVelocity().x * dt * 0.5;
	vaisseaux_position.y += de_vaisseaux.at(i)->Getp_body()->GetLinearVelocity().y * dt * 0.5;
	
	
        for (int j = 0; j < de_planete.size(); j++ )
        {
            b2Vec2 planet_position = de_planete.at(j)->Getp_body()->GetWorldCenter();
            b2Vec2 between_distance (0,0);
            between_distance = vaisseaux_position - planet_position;


            if (between_distance.Length() < de_planete.at(j)->get_radius_gravitation())
            {
                float force = (CONST_GRAVITATION * de_planete.at(j)->Getp_body()->GetMass()) / pow(between_distance.Length(), 2);

                between_distance.x = between_distance.x * force;
                between_distance.y = between_distance.y * force;
                between_distance = -between_distance;

                de_vaisseaux.at(i)->Getp_body()->ApplyForce(between_distance,de_vaisseaux.at(i)->Getp_body()->GetWorldCenter(),true);
            }
            

            
	}
    }
}
