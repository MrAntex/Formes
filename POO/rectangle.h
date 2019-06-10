#ifndef DEF_RECTANGLE
#define DEF_RECTANGLE
	
#include "Forme.h"



#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



using namespace sf;

class Rectangle : public Forme
{
	//Largeur , hauteur
	float l = 3.0f, h = 5.0f;
	//Point modif;

public:

	Rectangle(Point _ancre, uint _largeur, uint _hauteur ,Color coul);

	Rectangle(Rectangle const& orig);

	~Rectangle() override;

	inline double perimetre() const { return(l + h) * 2; };

	inline void setLargeur(uint _largeur) { l = _largeur; };
	inline void setHauteur(uint _hauteur) { h = _hauteur; };

	inline uint getLargeur() const { return l; };
	inline uint getHauteur() const { return h; };
	
	void dessiner(RenderWindow& fenetre, bool isactiv = false) const override;

	//ancre de déplacement configuré sur la surface
	virtual bool isOver(Vector2f curseur);


	//ancre de modification
	//inline Point ancre_modif(Vector2f curseur) { modif.setAncre = curseur; };
	


};

#endif

/*inline Vector2f getAncre() const { return ancre; };

	inline void setAncre(Vector2f _ancre) { ancre = _ancre; };

	inline void move(Vector2f ancre2) { ancre = ancre + ancre2; };
	*/
