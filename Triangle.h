#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "SFML/Graphics/Color.hpp"
#include "MATH folder/Array_Math.h"

class Triangle
{
	sf::Color _color;
	Vector4D _points[3];

public:

	Triangle() = default;

	Triangle(Vector4D p1, Vector4D p2, Vector4D p3, sf::Color color = { 90,145,30,50 })
		:_points{p1,p2,p3},_color(color){}

	Vector3D position()
	{
		return Vector3D(_points[0] + _points[1] + _points[2])/3;
	}

	Triangle operator * (Array4x4 arr)
	{
		return Triangle(arr*_points[0], arr*_points[1], arr*_points[2], _color);
	}

	Vector4D operator[](int i)
	{
		return _points[i];
	}
	sf::Color getColor() { return _color; }

};

#endif