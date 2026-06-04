
#include	"Scene.h"

float dt;
sf::Clock dtClock;

int wW = 1280, wH = 720;

Object cube;
bool DevmodeON = false;

Scene S
(
	&cube,
	new Camera(wW, wH, 0.0001, 100, 60)
);

void UpdateDt()
{
	dt = dtClock.restart().asSeconds();
}

int main()
{

	sf::RenderWindow window(
		sf::VideoMode(wW, wH),
		"SFML works!",
		sf::Style::None
	);

	window.setMouseCursorVisible(0);
	window.setFramerateLimit(60);

	cube.Cube();
	cube.Translate(Vector3D{ 0,0,5 });
	cube.Scale(Vector3D{ 1,1,1 });

	while (window.isOpen())
	{
		UpdateDt();

		//S.UpdateScene(dt);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)	window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Tilde)
					if (DevmodeON)
						DevmodeON = false;
					else
						DevmodeON = true;
			}

			//if (event.type == sf::Event::MouseMoved)
			//{
			//	float
			//		mouseX = 0, 
			//		mouseY = 0;
			//
			//	//if (sf::Mouse::getPosition().x > wW / 2 + window.getPosition().x) mouseX = -1.5;
			//	//if (sf::Mouse::getPosition().x < wW / 2 + window.getPosition().x) mouseX = 1.5;
			//	//
			//	if (sf::Mouse::getPosition().y > wH / 2 + window.getPosition().y) mouseY = -1.25;
			//	if (sf::Mouse::getPosition().y < wH / 2 + window.getPosition().y) mouseY = 1.25;
			//	//
			//
			//	if(mouseX !=0 || mouseY!=0)
			//		cube.RotateObject(Vector3D(mouseX*dt, mouseY*dt));
			//
			//}
		}

		//looks like a mess
		//trully is a mess

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			cube.RotateObject(Vector3D(1.25*dt, 0, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			cube.RotateObject(Vector3D(-1.25*dt, 0, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			cube.RotateObject(Vector3D(0, 1.25*dt, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			cube.RotateObject(Vector3D(0, -1.25*dt, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			cube.RotateObject(Vector3D(0, 0, -1.25*dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			cube.RotateObject(Vector3D(0, 0, 1.25*dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			cube.Translate(Vector3D(1.25*dt, 0, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			cube.Translate(Vector3D(-1.25*dt, 0, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			cube.Translate(Vector3D(0, 0, 1.25*dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			cube.Translate(Vector3D(0, 0, -1.25*dt));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			cube.Translate(Vector3D(0, 1.25*dt, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
			cube.Translate(Vector3D(0, -1.25*dt, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		window.clear(sf::Color(151, 198, 232));

		S.DrawScene(&window, DevmodeON);

		//sf::Mouse::setPosition(sf::Vector2i(
		//	window.getPosition().x + wW / 2,
		//	window.getPosition().y + wH / 2)
		//);

		window.display();

	}

	return 0;
}