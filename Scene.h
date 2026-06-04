#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/VertexArray.hpp"

class Scene
{
	Object *obj;
	Camera *cam;

	//int OveralFrames = 0;

public:
	Scene() = default;

	Scene(Object *o, Camera *c)
		:obj(o), cam(c){}

	void UpdateScene(/*float dt*/)
	{
		/*float rotate = dt * 0.5;

		(*obj).RotateObject(Vector3D{ 
			0,
			rotate,
			0
			});*/
				
	}

	void DrawScene(sf::RenderWindow *window,bool dmON)
	{
		std::vector<Triangle> tri{};

		tri = cam->project(*obj,dmON);

		int sOB = 0;

		for (auto T : tri)
		{
			std::vector<sf::Vertex> verts{};

			//sf::Color(92, 96, 122, 50)
			sf::Color color;
			
			color = T.getTriColor();

			sf::Vertex begin(sf::Vector2f(T[0].x(), T[0].y()),color);

			for (int i = 0; i < 3; i++)
			{
				sf::Vertex vert(
					sf::Vector2f(T[i].x(), T[i].y()),
					color);

				sOB += sizeof(vert);	verts.push_back(vert);

			}

			verts.push_back(begin);

			//window->draw(tris,3,sf::Triangles);
			if (dmON)
				window->draw(&verts[0], verts.size(), sf::PrimitiveType::LineStrip);
			else
				window->draw(&verts[0], verts.size(), sf::PrimitiveType::Triangles);
			//sOB += sizeof(triangle);
		}

		if (dmON) 
		{
			std::string mesage{};

			sf::Text data;	sf::Font font;
			font.loadFromFile("Orange Kid.otf");
			data.setFont(font);		data.setPosition(0, 0);
			data.setFillColor(sf::Color::Black);

			mesage += "dev mode is active\n";
			mesage += "triangles on screen = "+std::to_string(tri.size())+'\n';
			mesage += "size of object on screen(B) = " + std::to_string(sOB/8)+'\n';
			//mesage += "Overal frames = " + std::to_string(OveralFrames)+'\n';

			data.setString(mesage);

			window->draw(data);

		}

	}
};

#endif