#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

namespace My {
	class Triangle : public Shape {
	public:
		//__________________________COPY__________________________________
		Triangle* Copy() override {
			return new Triangle(*this);
		}
		Triangle(const Triangle& copy) : Triangle(copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}

		//____________________________________________________CONSTRUCTORS_____________________________________________________________
		Triangle() :                                                          Shape() {}
		Triangle(Vector2f center) :                                           Shape(center) {}
		Triangle(Vector2f center, Vector2f scale) :                           Shape(center, scale) {}
		Triangle(Vector2f center, Vector2f scale, float angle) :              Shape(center, scale, angle) {}
		Triangle(Vector2f center, Vector2f scale, float angle, Color color) : Shape(center, scale, angle, color) {}
		virtual ~Triangle() = default;

		//_______________________________________________________DRAW___________________________________________________________________
		void Draw(RenderWindow& window) override {
			ConvexShape shape;
			//_______________________POSITION___________________________
			shape.setPointCount(3);
			shape.setPoint(0, Vector2f(40.f, 0.f));
			shape.setPoint(1, Vector2f(0.f, 70.f));
			shape.setPoint(2, Vector2f(80.f, 70.f));
			//__________________________________________________________
			shape.setRotation(this->GetAngle());
			shape.setScale(this->GetScale());
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

