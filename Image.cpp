#include "Image.h"

Img::Img(Point _ancre, String _text) : Forme(_ancre, couleur), text(_text)
{
	Sprite sprite;
	Texture texture;
	if (!texture.loadFromFile(text))
	{
		cerr << "erreur";
	}
	sprite.setTexture(texture);
	setLH(Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
}

Img::Img(Img const& orig) : Img(orig.getPoint().getAncre(), orig.text)
{}

Img::~Img()
{}
/*
void Img::ecrire(ostream & os)
{
	os << "Img ";
	Forme::ecrire(os);
	os << text;
}
*/

void Img::dessiner(RenderWindow& fenetre, bool isactive) const
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
		sprite.setColor(Color(255, 255, 255, opacite));
		fenetre.draw(sprite);
	}
}

bool Img::isOver(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
	if (curseur.x > getPoint().getAncre().x && curseur.y > getPoint().getAncre().y && curseur.x < ancre2.x && curseur.y < ancre2.y)
		return true;
	else
		return false;
}

bool Img::modif(Vector2f curseur)
{
	Vector2f ancre2 = Vector2f(getPoint().getAncre().x + LH.x, getPoint().getAncre().y + LH.y);
	Vector2f ancre3 = Vector2f(ancre2.x + 8, ancre2.y + 8);
	if (curseur.x > ancre2.x && curseur.y > ancre2.y && curseur.x < ancre3.x && curseur.y < ancre3.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vector2f Img::Size(Vector2f curseur)
{
	Vector2f _taille = curseur - getPoint().getAncre();
	setLH(_taille);
	return(_taille);
}