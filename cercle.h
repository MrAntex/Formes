#ifndef DEF_CERCLE
#define DEF_CERCLE

#include "Point.h"
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
	~Cercle();

	//Couleur statique

	inline void setTaille(float t) { taille = t; };

	virtual void dessiner(sf::RenderWindow& fenetre, bool isactive = false) const;


};

#endif