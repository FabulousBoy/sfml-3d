
#include"Scene.h"

float dt;
sf::Clock dtClock;

int wW = 640,	wH = 640;

Object cube;

Scene S
(
	&cube,
	new Camera(wW,wH,100,0.1,90)
);

void UpdateDt()
{
	dt = dtClock.restart().asSeconds();
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(wW, wH), "SFML works!");
	window.setFramerateLimit(60);

	cube.Cube();
	cube.Translate(Vector3D{0,0,7});
	cube.Scale(Vector3D{3,3,3});

	while (window.isOpen())
	{
		UpdateDt();
		S.UpdateScene(dt);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
		}
		window.clear(sf::Color(100, 110, 150, 100));
		
		
		S.DrawScene(&window);

		window.display();

	}

	return 0;
}