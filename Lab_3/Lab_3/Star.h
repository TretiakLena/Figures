#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

namespace My {
	class Star : public Shape {
	public:
		//__________________________COPY__________________________________
		Star* Copy() override {
			return new Star(*this);
		}
		Star(const Star& copy) : Star(copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}

		//____________________________________________________CONSTRUCTORS_____________________________________________________________
		Star() :                                                          Shape() {}
		Star(Vector2f center) :                                           Shape(center) {}
		Star(Vector2f center, Vector2f scale) :                           Shape(center, scale) {}
		Star(Vector2f center, Vector2f scale, float angle) :              Shape(center, scale, angle) {}
		Star(Vector2f center, Vector2f scale, float angle, Color color) : Shape(center, scale, angle, color) {}
		virtual ~Star() = default;

		//_______________________________________________________DRAW___________________________________________________________________
		void Draw(RenderWindow& window) override {
			ConvexShape shape;
			//_______________________POSITION___________________________
			shape.setPointCount(10);
			shape.setPoint(0, Vector2f(40.f, 0.f));
			shape.setPoint(1, Vector2f(30.f, 32.f));
			shape.setPoint(2, Vector2f(0.f, 32.f));
			shape.setPoint(3, Vector2f(20.f, 55.f));
			shape.setPoint(4, Vector2f(10.f, 90.f));
			shape.setPoint(5, Vector2f(40.f, 70.f));
			shape.setPoint(6, Vector2f(70.f, 90.f));
			shape.setPoint(7, Vector2f(60.f, 55.f));
			shape.setPoint(8, Vector2f(80.f, 32.f));
			shape.setPoint(9, Vector2f(50.f, 32.f));

			//__________________________________________________________
			shape.setRotation (this->GetAngle());
			shape.setScale    (this->GetScale());
			shape.setFillColor(this->GetColor());

			//____________________FOR_TRANSPARENT________________________
			if (trans) {
				shape.setFillColor(Color::Transparent);
			}
			//____________________FOR_TRAIL_______________________________
			if (trail) {
				for (auto i : history) {
					shape.setPosition(i.x, i.y);
					window.draw(shape);
				}
			}
			shape.setPosition(this->GetPosition().x, this->GetPosition().y);

			window.draw(shape);
		}
	};
}

