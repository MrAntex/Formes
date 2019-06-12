#ifndef DEF_CERCLE
#define DEF_CERCLE

#include "Forme.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <istream>
#include <ostream>

using namespace sf;

typedef unsigned int uint;

class Cercle : public Forme
{
	float taille;


public:
	
	Cercle(Point _ancre, float _taille, Color coul);

	Cercle(istream & is);

	Cercle(Cercle const& orig);


	//Destructeur
	~Cercle() override;

	//Sauvegarder/charger
	
	virtual void ecrire(ostream & os) const override;
	
	//Couleur statique
	inline virtual void  move(Vector2f mouse) { setPoint(Vector2f(mouse.x - taille, mouse.y - taille)); };

	inline void setTaille(float t) { taille = t; };

	virtual void dessiner(RenderWindow& fenetre, bool isactive = false)const override;

	virtual bool isOver(Vector2f curseur);
	
	//Vérification de si le curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur);
	virtual Vector2f Size(Vector2f curseur);
};

#endif