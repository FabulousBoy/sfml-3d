#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"

class Camera
{
	Array4x4 SP;
	 
	float _asp = 0;

public:
	Camera() = default;

	Camera(int W, int H, float zF, float zN,float fov)
	{
		_asp = W/H;

		SP = Array4x4::Screen(W, H)* Array4x4::Projection_Array(fov,_asp,zF,zN);
	}

	std::vector<Triangle> project(Object O)
	{
		std::vector<Triangle> tris{};

		Array4x4 M = O.model();
		//M.GetArr();

		for (auto t : O.getTris())
		{
			Triangle p = (t * M * SP);

			Triangle p_norm = Triangle(
				p[0] / p[0].w(),
				p[1] / p[1].w(),
				p[2] / p[2].w());

			tris.emplace_back(p_norm);
			//tris.emplace_back(p);
		}

		return tris;

	}
};

#endif