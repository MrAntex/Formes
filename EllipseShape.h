#pragma once
#ifndef DEF_ELLIPSESHAPE
#define DEF_ELLIPSESHAPE

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <istream>
#include <ostream>

using namespace sf;


class EllipseShape : public Shape
{
public:
	explicit EllipseShape(const Vector2f& radius = Vector2f(0, 0)) :
		m_radius(radius)
	{
		update();
	}

	void setRadius(const Vector2f& radius)
	{
		m_radius = radius;
		update();
	}

	const Vector2f& getRadius() const
	{
		return m_radius;
	}

	virtual size_t getPointCount() const
	{
		return 30; // fixé, mais ça pourrait tout aussi bien être un attribut de la classe
	}

	virtual Vector2f getPoint(size_t index) const
	{
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return Vector2f(m_radius.x + x, m_radius.y + y);
	}

private:

	Vector2f m_radius;
};

#endif