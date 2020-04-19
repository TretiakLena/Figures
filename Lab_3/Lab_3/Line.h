#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

namespace My {
	class Line : public Shape {
	public:
		//__________________________COPY__________________________________
		Line* Copy() override {
			return new Line(*this);
		}
		Line(const Line& copy) : Line(copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}

		//____________________________________________________CONSTRUCTORS_____________________________________________________________
		Line() :                                                          Shape() {}
		Line(Vector2f center) :                                           Shape(center) {}
		Line(Vector2f center, Vector2f scale) :                           Shape(center, scale) {}
		Line(Vector2f center, Vector2f scale, float angle) :              Shape(center, scale, angle) {}
		Line(Vector2f center, Vector2f scale, float angle, Color color) : Shape(center, scale, angle, color) {}
		virtual ~Line() = default;

		//_______________________________________________________DRAW___________________________________________________________________
		void Draw(RenderWindow& window) override {
			ConvexShape shape;
			//_______________________POSITION___________________________
			shape.setPointCount(4);
			shape.setPoint(0, Vector2f(0.f, 0.f));
			shape.setPoint(1, Vector2f(0.f, 50.f));
			shape.setPoint(2, Vector2f(2.f, 50.f));
			shape.setPoint(3, Vector2f(2.f, 0.f));
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

