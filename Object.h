#ifndef OBJECT_H
#define OBJECT_H

#include "Triangle.h"
#include <vector>
#include <string>

class Object
{
	std::vector<Triangle> tris{};
	std::string name;

	//position of object
	Vector3D pos{ 0,0,0 };
	//current angle
	Vector3D angl{ 0,0,0 };

	Array4x4 t_matrix = Array4x4::Identity();

public:
	
	Object() = default;

	void RotateObject(Vector3D R)
	{
		angl = angl + R;		
		transform(Array4x4::Rotation(R));

		//t_matrix.GetArr();
	}
	void Scale(Vector3D S)
	{
		transform(Array4x4::Scale(S));
	}

	void transform(Array4x4 t)
	{
		t_matrix = t*t_matrix;
	}

	void Cube()
	{
		tris = 
		{

			{ Vector4D{-1.0, -1.0, -1.0, 1.0},    Vector4D{-1.0, 1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, -1.0, 1.0} },
			{ Vector4D{-1.0, -1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, -1.0, 1.0},    Vector4D{1.0, -1.0, -1.0, 1.0} },

			{ Vector4D{1.0, -1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, 1.0, 1.0} },
			{ Vector4D{1.0, -1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, 1.0, 1.0},    Vector4D{1.0, -1.0, 1.0, 1.0} },

			{ Vector4D{1.0, -1.0, 1.0, 1.0},    Vector4D{1.0, 1.0, 1.0, 1.0},    Vector4D{-1.0, 1.0, 1.0, 1.0} },
			{ Vector4D{1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, 1.0, 1.0, 1.0},    Vector4D{-1.0, -1.0, 1.0, 1.0} },

			{ Vector4D{-1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, 1.0, 1.0, 1.0},    Vector4D{-1.0, 1.0, -1.0, 1.0} },
			{ Vector4D{-1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, 1.0, -1.0, 1.0},    Vector4D{-1.0, -1.0, -1.0, 1.0} },

			{ Vector4D{-1.0, 1.0, -1.0, 1.0},    Vector4D{-1.0, 1.0, 1.0, 1.0},    Vector4D{1.0, 1.0, 1.0, 1.0} },
			{ Vector4D{-1.0, 1.0, -1.0, 1.0},    Vector4D{1.0, 1.0, 1.0, 1.0},    Vector4D{1.0, 1.0, -1.0, 1.0} },

			{ Vector4D{1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, -1.0, -1.0, 1.0} },
			{ Vector4D{1.0, -1.0, 1.0, 1.0},    Vector4D{-1.0, -1.0, -1.0, 1.0},    Vector4D{1.0, -1.0, -1.0, 1.0} }
		};

	}

	Array4x4 model() { return  Array4x4::Translation(pos)*t_matrix; }

	void Translate(Vector3D dv)
	{
		pos = pos + dv;
	}

	std::vector<Triangle> getTris() { return tris; }
};

#endif