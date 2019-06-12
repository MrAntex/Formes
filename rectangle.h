#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE
	
#include "Forme.h"



#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

typedef unsigned int uint;
typedef unsigned long int ulong;

// "uint" et "ulong" sont déjà définis respectivement dans "Point.hpp" et "Forme.hpp", donc c'était inutile que je les redéfinisse ici,
// mais par habitude, je les ai remis.


using namespace sf;

class Rectangle : public Forme //: public Forme
{
	Vector2f LH; //Largeur , hauteur

public:

	Rectangle(Point _ancre,Vector2f _LH ,Color coul);

	Rectangle(Rectangle const& orig);

	~Rectangle() override;

	inline double perimetre() const { return(LH.x + LH.y) * 2; };
	
	//inline double perimetre() const { return(l + h) * 2; };

	inline void setL(float _largeur) { LH.x = _largeur; };
	inline void setH(float _hauteur) { LH.y = _hauteur; };
	inline void setLH(Vector2f lh) { LH = lh; };

	inline float getL() const { return LH.x; };
	inline float get() const { return LH.y; };
	inline Vector2f getLH() const { return LH; };

	inline virtual void  move(Vector2f mouse) { setPoint(Vector2f(mouse.x - LH.x / 2, mouse.y - LH.y / 2)); };
	
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false) const override;

	virtual bool isOver(Vector2f curseur);

	virtual bool modif(Vector2f curseur);

	virtual Vector2f Size(Vector2f curseur);

};

#endif

/*inline Vector2f getAncre() const { return ancre; };

	inline void setAncre(Vector2f _ancre) { ancre = _ancre; };

	inline void move(Vector2f ancre2) { ancre = ancre + ancre2; };
	*/
