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
	Vector2f LH;
	
public:

	//Constructeur d'un rectangle
	Rectangle(Point _ancre, Vector2f _LH ,Color coul);
	
	Rectangle(istream & is);

	//Copie du rectangle
	Rectangle(Rectangle const& orig);

	//Destructeur du rectangle
	~Rectangle() override;

	//sauvegarder/charger
	virtual void ecrire(ostream & os);
	
	inline double perimetre() const { return(LH.x + LH.y) * 2; };

	inline void setL(float _largeur) { LH.x = _largeur; };
	inline void setH(float _hauteur) { LH.y = _hauteur; };
	inline void setLH(Vector2f lh) { LH = lh;  };

	inline float getL() const { return LH.x; };
	inline float get() const { return LH.y; };
	inline Vector2f getLH() const { return LH; };
	
	inline virtual void  move(Vector2f mouse) { setPoint(Vector2f(mouse.x - LH.x/2,mouse.y - LH.y/2)); };
	
	void dessiner(RenderWindow& fenetre, bool isactiv = false) const override;

	//ancre de déplacement configuré sur la surface
	virtual bool isOver(Vector2f curseur);

	//Vérification de si le curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur); 
	virtual Vector2f Size(Vector2f curseur);

};
#endif

