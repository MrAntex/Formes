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
	float l = 3.0f, h = 5.0f; //Largeur , hauteur

public:

	Rectangle(Point _ancre,uint _largeur, uint _hauteur ,Color coul);

	Rectangle(Rectangle const& orig);

	~Rectangle();

	
	
	//inline double perimetre() const { return(l + h) * 2; };

	inline void setLargeur(uint _largeur) { l = _largeur; };
	inline void setHauteur(uint _hauteur) { h = _hauteur; };

	inline uint getLargeur() const { return l; };
	inline uint getHauteur() const { return h; };
	
	virtual void dessiner(RenderWindow& fenetre, bool isactive = false) const;

};

#endif

/*inline Vector2f getAncre() const { return ancre; };

	inline void setAncre(Vector2f _ancre) { ancre = _ancre; };

	inline void move(Vector2f ancre2) { ancre = ancre + ancre2; };
	*/
