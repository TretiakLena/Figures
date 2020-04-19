#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Main.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Index.h"
#include "Agregat.h"
#include "Triangle.h"
#include "Star.h"
#include "Line.h"
using namespace sf;

int main()
{
	ContextSettings settings;			// это настройки графики
	settings.antialiasingLevel = 2;		// чем выше тем лучше
	
	RenderWindow window(VideoMode({ 1380, 768 }), "SFML works!");
	window.setFramerateLimit(60);	    // ограничим возможности программы
	Event event{};

	vector<My::Shape*> shapes{};
	auto ChangeRGBA = true;
	auto trail = false;
	Index* index = Index::CreateIndex(0);
	auto RGBA = My::Main::COLOR;

	while (window.isOpen())
	{
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
#pragma region MOVE
			//_____________________________________MOVE___________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
				shapes[*index]->ChangePosition(Vector2f(-My::Main::SPEED, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
				shapes[*index]->ChangePosition(Vector2f(+My::Main::SPEED, 0.f));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
				shapes[*index]->ChangePosition(Vector2f(0.f, -My::Main::SPEED));
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
				shapes[*index]->ChangePosition(Vector2f(0.f, +My::Main::SPEED));
			}
#pragma endregion My move			
#pragma region SCALE
			//_____________________________SCALE______________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::X)) {
				shapes[*index]->ChangeScale(-My::Main::SCALE);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::V)) {
				shapes[*index]->ChangeScale(My::Main::SCALE);
			}
#pragma endregion My scale
#pragma region ANGLE
			//___________________________________ANGLE_________________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
				shapes[*index]->ChangeAngle(-My::Main::ANGLE);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::F)) {
				shapes[*index]->ChangeAngle(My::Main::ANGLE);
			}
#pragma endregion My angle
#pragma region COLOR
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
					shapes[*index]->ChangeColor(RGBA, 0, 0, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::P)) {
					shapes[*index]->ChangeColor(0, RGBA, 0, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::RBracket)) {
					shapes[*index]->ChangeColor(0, 0, RGBA, 0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::LBracket)) {
					shapes[*index]->ChangeColor(0, 0, 0, RGBA);
			}
#pragma endregion My color			
#pragma region FIGURES
			//_____________________________________FIGURES________________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::C) {
				shapes.push_back(new My::Circle());
				index->LimitUp();
				index->IndexUp();
				index->SetIndex(shapes.size() - 1);

			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::R) {
				shapes.push_back(new My::Rectangle());
				index->LimitUp();
				index->IndexUp();
				index->SetIndex(shapes.size() - 1);
			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::A) {
				shapes.push_back(new My::Triangle());
				index->LimitUp();
				index->IndexUp();
				index->SetIndex(shapes.size() - 1);
			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::S) {
				shapes.push_back(new My::Star());
				index->LimitUp();
				index->IndexUp();
				index->SetIndex(shapes.size() - 1);
			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::L) {
				shapes.push_back(new My::Line());
				index->LimitUp();
				index->IndexUp();
				index->SetIndex(shapes.size() - 1);
			}
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::Delete) {
				shapes.erase(shapes.begin() + *index);
				index->LimitDown();
				index->IndexDown();
			}
#pragma endregion My figures
#pragma region FOCUS
			//_________________________________FOCUS________________________________________________________
			if (Keyboard::isKeyPressed(Keyboard::Key::PageUp)) {
				index->IndexUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::PageDown)) {
				index->IndexDown();
			}
#pragma endregion My focus
#pragma region TRAIL
			//__________________________________TRAIL_________________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::T) {
				shapes[*index]->SwitchTrail();
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Q)) {
				shapes[*index]->ForgetHistory();
			}
#pragma endregion My trail
#pragma region TRANSPARENT
			//______________________________________TRANSPARENT________________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::W) {
				shapes[*index]->SwitchTrans();
			}
#pragma endregion My transparent			
#pragma region AGREGAT
			//___________________________________________AGREGAT_____________________________________________
			if (event.type == Event::EventType::KeyReleased and event.key.code == Keyboard::Key::Enter) {
				shapes.push_back(new My::Agregat({shapes[*index]->Copy(), shapes[*index - 1]->Copy()}));
				index->LimitUp();
				index->SetIndex(shapes.size() - 1);
			}
#pragma endregion My agregat
#pragma region DISPLAY
			//_______________________________________DISPLAY_________________________________________________
			window.clear();
			for (auto& i : shapes) {
				i->Draw(window);
			}
			window.display();
#pragma endregion My display
		}
	
	}
	delete index;
	system("PAUSE > nul");
	return 0;
}
