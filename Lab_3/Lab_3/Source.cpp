#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Main.h"
#include "Circle.h"
#include "Rectangle.h"
// убрал лишние хедеры
#include "Shape.h"

using namespace sf;
using namespace std;

auto main() -> int
{
	ContextSettings settings;			// это настройки графики
	settings.antialiasingLevel = 2;		// чем выше тем лучше
										// сделал, чтобы твой комп не умирал от боли
	
	RenderWindow window(VideoMode({ 1380, 768 }), "SFML works!");
	window.setFramerateLimit(60);	    // ограничим возможности твоей программы, а то на мощных компах рывками всЄ
	Event event{};

	vector<My::Shape*> shapes{};
	//bool ChangeRGBA = true;     // кто-то €вно схватил
	//bool trail = 0;			  // бипол€рочку
	auto ChangeRGBA = true;
	auto trail = false;
	auto RGBA = My::Main::COLOR;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			
			//_____________________________________MOVE___________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			{
				//circle.ChangePosition(Vector2f(-My::Main::SPEED, 0.f));
				shapes[shapes.size() - 1]->ChangePosition(Vector2f(-My::Main::SPEED, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			{
				shapes[shapes.size() - 1]->ChangePosition(Vector2f(+My::Main::SPEED, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			{
				shapes[shapes.size() - 1]->ChangePosition(Vector2f(0.f, -My::Main::SPEED));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			{
				shapes[shapes.size() - 1]->ChangePosition(Vector2f(0.f, +My::Main::SPEED));
			}
			
			//_____________________________SCALE______________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::X))
			{
				shapes[shapes.size() - 1]->ChangeScale(-My::Main::SCALE);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::V))
			{
				shapes[shapes.size() - 1]->ChangeScale(My::Main::SCALE);
			}

			//___________________________________ANGLE_________________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::D))
			{
				shapes[shapes.size() - 1]->ChangeAngle(-My::Main::ANGLE);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::F))
			{
				shapes[shapes.size() - 1]->ChangeAngle(My::Main::ANGLE);
			}
			
			//______________________________________COLOR____________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::I){
				ChangeRGBA = !ChangeRGBA;
				if (ChangeRGBA) {
					RGBA = My::Main::COLOR;
				}
				else {
					RGBA = -My::Main::COLOR;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::O)) {
					shapes[shapes.size() - 1]->ChangeColor(RGBA, 0, 0, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::P)) {
					shapes[shapes.size() - 1]->ChangeColor(0, RGBA, 0, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::RBracket)) {
					shapes[shapes.size() - 1]->ChangeColor(0, 0, RGBA, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::LBracket)) {
					shapes[shapes.size() - 1]->ChangeColor(0, 0, 0, RGBA);
			}
			
			//_____________________________________FIGURES________________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::C)
			{
				shapes.push_back(new My::Circle());
			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::R)
			{
				shapes.push_back(new My::Rectangle());
			}

			//__________________________________TRAIL_________________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::T)
			{
				trail = !trail;
				std::cout << trail << endl;
			}
			//if (trail == 0) так никто не пишет
			if (!trail)
			{
				window.clear();
			}

			//_______________________________________DISPLAY_________________________________________________
			for (auto& i : shapes)
			{
				i->Draw(window);
			}
			window.display();
		}
		
	}
	system("pause > NUL");
	return EXIT_SUCCESS;
}
