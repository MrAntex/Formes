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
	//Point modif;
	
public:

	//Constructeur d'un rectangle
	Rectangle(Point _ancre, Vector2f _LH ,Color coul);
	
	//Copie du rectangle
	Rectangle(Rectangle const& orig);

	//Destructeur du rectangle
	~Rectangle() override;

	inline double perimetre() const { return(LH.x + LH.y) * 2; };

	inline void setL(float _largeur) { LH.x = _largeur; };
	inline void setH(float _hauteur) { LH.y = _hauteur; };
	inline void setLH(Vector2f lh) { LH = lh;  };
	inline void setDim(Vector2f curseur) { LH = Size(curseur); };

	inline float getL() const { return LH.x; };
	inline float get() const { return LH.y; };
	inline Vector2f getLH() const { return LH; };
	

	void dessiner(RenderWindow& fenetre, bool isactiv = false) const override;

	//ancre de déplacement configuré sur la surface
	virtual bool isOver(Vector2f curseur);

	//Vérification de si le curseur sur l'ancre de modification
	virtual bool modif(Vector2f curseur); 
	//inline virtual void pt_modif(Vector2f curseur) { Rectangle::setLH(curseur - getPoint().getAncre()); };
	inline virtual string type(Vector2f curseur) { if(modif(curseur)) return "Rectangle"; };

};
#endif

