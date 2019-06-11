#ifndef DEF_POINT
#define DEF_POINT

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <istream>
#include <ostream>

using namespace sf;
	
typedef unsigned int uint;

class Point
{
	/*static*/ float /*const*/ taille = 5.0f;
	Vector2f ancre;
	Color couleur = Color::Black;

public:
	//Différentes initialisations de points
	Point(Vector2f _ancre);

	//Copie du point
	Point(Point const& orig);

	//Destructeur
	~Point();

	//Couleur statique

	inline Vector2f getAncre()const { return ancre; };

	inline void setTaille(float t) { taille = t; };

	void setAncre(Vector2f _ancre) { ancre = _ancre; };

	bool isOver(Vector2f _ancre) const;

	void dessiner(RenderWindow& fenetre, bool isactive = false) const;

};

#endif