#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE

#include "Forme.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <istream>
#include <ostream>

using namespace sf;

class Triangle : public Forme
{
	Point a2, a3;
public:

	Triangle(Point _ancre, Point _a2, Point _a3, Color coul);
	Triangle(Triangle const& orig);

	~Triangle() override;

	//inline ConvexShape getTriangle() const { triangle.setPointCount(3); return triangle; };	

	inline Point getA2()const { return a2; };

	inline Point geta3()const { return a3; };

	inline void setSommet( Vector2f _a2, Vector2f _a3) {a2 = _a2; a3 = _a3; };

	void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);

	//Ancre de modification
	virtual bool modif(Vector2f curseur);
	inline virtual string type(Vector2f curseur) {  return "oui"; };
};
#endif