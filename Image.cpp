
#include "Image.h"

Img::Img(Point _ancre, String _text, Color coul) : Forme(_ancre,coul), text(_text)
{}

Img::Img(Img const & orig) :  Img(orig.getPoint().getAncre(), orig.text, orig.getColor())
{}

Img::~Img()
{}

void Img::dessiner(RenderWindow & fenetre, bool isactive) const
{
	Texture texture;
	Sprite sprite;
	if (!texture.loadFromFile(text))
	{
		cerr << "erreur";
	}
	else
	{
		sprite.setTexture(texture);
		sprite.setPosition(getPoint().getAncre());
		fenetre.draw(sprite);
		Forme::dessiner(fenetre, isactive);
		//cout << sprite.getGlobalBounds().height << endl;
		//cout << sprite.getGlobalBounds().width << endl;
	}
}

bool Img::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + 6, getPoint().getAncre().y + 6);
	if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
	{

		return true;

	}
	else
	{
		return false;
	}
}

bool Img::modif(Vector2f curseur)
{
	return false;
}
