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

	Cercle(Cercle const& orig);


	//Destructeur
	~Cercle() override;

	//Couleur statique

	inline void setTaille(float t) { taille = t; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);

};

#endif