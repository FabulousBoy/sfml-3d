#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "SFML/Graphics/Color.hpp"
#include "MATH folder/Array_Math.h"

class Triangle
{
	Vector4D _points[3];
	Vector3D _norm{0,0,0};

	sf::Color triColor;

public:

	Triangle() = default;

	Triangle
	(
		Vector4D p1, 
		Vector4D p2, 
		Vector4D p3

	) :_points{ p1,p2,p3 } {	calculateNormal();	}

	Vector3D position()
	{
		return Vector3D(_points[0] + _points[1] + _points[2])/3;
	}

	void calculateNormal()
	{
		Vector3D V1 = Vector3D(_points[1] - _points[0]);
		Vector3D V2 = Vector3D(_points[2] - _points[0]);

		Vector3D cross = V1.cross(V2);

		if (cross.abs() >= 0.0001)
			_norm = cross.normalize();
		else
			_norm = Vector3D(0, 0, 0);
	}

	void SetColor(float R, float G, float B)
	{
		triColor = sf::Color(R, G, B);
	}

	sf::Color getTriColor() { return triColor; }

	Vector3D norm() { return _norm; }

	Triangle operator * (Array4x4 arr)
	{
		return Triangle(
			arr*_points[0],
			arr*_points[1],
			arr*_points[2]
		);
	}

	Vector4D operator[](int i)
	{
		return _points[i];
	}

};

#endif