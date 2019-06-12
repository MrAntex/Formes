#ifndef DEF_POINT
#define DEF_POINT

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

using namespace sf;
using namespace std;
	
typedef unsigned int uint;

class Point
{
	float taille = 8.0f;
	Vector2f ancre;
	Color couleur = Color::Black;

public:
	//Différentes initialisations de points
	Point(Vector2f _ancre);

	//Copie du point
	Point(Point const& orig);
	
	Point(istream &is);

	//Destructeur
	~Point();

	//Couleur statique

	inline Vector2f getAncre()const { return ancre; };

	inline void setTaille(float t) { taille = t; };
	inline Vector2f setX(float _ancre) { ancre.x = _ancre; };
	inline Vector2f setY(float _ancre) { ancre.y = _ancre; };

	void setAncre(Vector2f _ancre) { ancre = _ancre; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const;

};

#endif