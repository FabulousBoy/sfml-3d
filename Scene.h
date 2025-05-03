#ifndef SCENE_H
#define SCENE_H

#include "Camera.h"

#include "SFML/Graphics.hpp"

class Scene
{
	Object *obj;
	Camera *cam;

public:
	Scene() = default;

	Scene(Object *o, Camera *c)
		:obj(o), cam(c){}

	void UpdateScene()
	{

	}

	void DrawScene(sf::RenderWindow *window)
	{
		std::vector<Triangle> tri{};

		tri = cam->project(*obj);

		for (auto T : tri)
		{
			sf::ConvexShape triangle(3);
			triangle.setFillColor(T.getColor());

			triangle.setOutlineThickness(1);
			triangle.setOutlineColor(sf::Color::Black);

			triangle.setPoint(0, sf::Vector2f
			(
				T[0].x(), T[0].y()
			));
			triangle.setPoint(1, sf::Vector2f
			(
				T[1].x(), T[1].y()
			));
			triangle.setPoint(2, sf::Vector2f
			(
				T[2].x(), T[2].y()
			));

			//window->draw(tris,3,sf::Triangles);
			window->draw(triangle);
		}
		/*for(auto t: triShape)
			window->draw(t);*/

		printf("%2g\n", tri[0][0].x());
		printf("%2g\n", tri[0][0].y());
		system("cls");
	}

};

#endif