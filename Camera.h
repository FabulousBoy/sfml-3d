#ifndef CAMERA_H
#define CAMERA_H

#include "Object.h"

class Camera
{
	Array4x4 SP;

	float _asp;
public:
	Camera() = default;

	Camera(int W, int H, float zN, float zF, float fov)
	{
		_asp = (float)W / (float)H;

		SP = Array4x4::Screen(W, H)*
			Array4x4::Projection_Array(fov, _asp, zF, zN);
	}

	std::vector<Triangle> project(Object O, bool devMode)
	{
		std::vector<Triangle> tris{};

		Array4x4 M = O.model();
		//M.GetArr();

		for (auto t : O.getTris())
		{
			Triangle p_m = t * M;

			float dot = p_m.norm().dot((Vector3D(0, 0, 0) - p_m[0]).normalize());

			if (!devMode)
			{
				if (dot < 0)		continue;
			}


				Triangle p_n = p_m * SP;

				Triangle p_norm = Triangle(
					p_n[0] / p_n[0].w(),
					p_n[1] / p_n[1].w(),
					p_n[2] / p_n[2].w());
				//92, 96, 122, 50
				if (!devMode)
					p_norm.SetColor(92 * dot, 96 * dot, 122 * dot);
				else
				{
					if (dot < 0)
						p_norm.SetColor(255, 0, 0);
					else
						p_norm.SetColor(0, 0, 255);
				}

				tris.emplace_back(p_norm);

			}

			return tris;

		}
	};

#endif