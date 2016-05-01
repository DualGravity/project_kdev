#include "worldengine.hpp"

Worldengine::Worldengine(sf::RenderWindow *t_app,b2World *t_world) :
p_app(t_app),p_world(t_world)
{
    view_factor = 1;
    p_gengine = new G_engine(p_app);

   

    Planete *p_sun;
    p_sun = new Planete(p_gengine,SUN_TEXTURE,p_world,1,0.5f,0,0,0,100,100,SUN_RADIUS,0);
    de_planete.push_back(p_sun);
    
     Planete *p_planete1;
    p_planete1 = new Planete(p_gengine,MERCURE_TEXTURE,p_world,1,0.5f,0,6000,-4000,100,100,MERCURE_RADIUS,0);
    de_planete.push_back(p_planete1);

    Vaisseaux *p_vaisseaux;
    p_vaisseaux = new Vaisseaux(p_gengine,"vaisseaux",p_world,1,0.0f,0.8f,0,50000000,6000000,140,0,2,10);
    de_vaisseaux.push_back(p_vaisseaux);

    /*Corps *p_corps;
    p_corps = new Corps(p_gengine,"Image/cb.bmp",p_world,1,0.3f,0,0,100,100,100,0);
    de_corps.push_back(p_corps);*/

    clock_ini_planete.restart();
    clock_gravstep.restart();
    clock_display.restart();
    
    
    
            lanceplanete();
}
Worldengine::~Worldengine()
{
    delete p_gengine;
    
    for (int i=0; i<de_corpsfix.size(); ++i)  //boucle pour suprimer les corps fixe
     {
        delete de_corpsfix.at(i);
     }

     for (int i=0; i<de_corps.size(); ++i)  //boucle pour suprimer les corps
     {
        delete de_corps.at(i);
     }

     for (int i=0; i<de_vaisseaux.size(); ++i)  //boucle pour suprimer les Vaisseaux
     {
        delete de_vaisseaux.at(i);
     }

     for (int i=0; i<de_planete.size(); ++i)  //boucle pour suprimer les Planetes
     {
        delete de_planete.at(i);
     }
}
void Worldengine::step(float dt)
{
  
  
    sf::Time elapsed00 = clock_gravstep.getElapsedTime();
    clock_gravstep.restart();
    
    grav.step(elapsed00.asSeconds(),de_corps,de_planete,de_vaisseaux);
    
    p_gengine->Changeview(view_factor,de_planete.at(0)->getVvec());
    view_factor = 1;
    
    


    sf::Time elapsed1 = clock_ini_planete.getElapsedTime();

    sf::Time elapsed02 = clock_ini_planete.getElapsedTime();
    
    if (elapsed02.asMilliseconds() > 16.66)
    {
      clock_ini_planete.restart();
      
       for (int i=0; i<de_corps.size(); ++i) //boucle actualiser les Corps
      {
	  de_corps.at(i)->actualise();
      }
      for (int i=0; i<de_vaisseaux.size(); ++i) //boucle actualiser Vaisseaux
      {
	  de_vaisseaux.at(i)->actualise(p_gengine->get_viewfactor());
      }

      for (int i=0; i<de_planete.size(); ++i) //boucle actualiser P
      {
	  de_planete.at(i)->actualise();
      }

    p_gengine->affiche_sprites();
    }
   

    p_world->Step(dt,VELOCITYITERATIONS, POSITIONITERATIONS);//Box2d Step

}
void Worldengine::changeview(float factor)
{
    view_factor = view_factor * factor;
}
void Worldengine::controlV1(float nb)
{
    if (nb == 8)
    de_vaisseaux.at(0)->applyForce(1);

    else if (nb == 4)
    de_vaisseaux.at(0)->turnLeft();

    else if (nb == 6)
    de_vaisseaux.at(0)->turnRight();

    else if (nb == 5)
    de_vaisseaux.at(0)->applyForce(-1);
    
    else
    de_vaisseaux.at(0)->default_state();

}

void Worldengine::controlV2(float nb)
{
    if (nb == 8)
    de_vaisseaux.at(1)->applyForce(1);

    else if (nb == 4)
    de_vaisseaux.at(1)->turnLeft();

    else if (nb == 6)
    de_vaisseaux.at(1)->turnRight();

    else if (nb == 5)
    de_vaisseaux.at(1)->applyForce(-1);

}
void Worldengine::lanceplanete()
{
    for (int i=0; i<de_planete.size(); ++i)
    {
        de_planete.at(i)->secondPini();
    }
}



