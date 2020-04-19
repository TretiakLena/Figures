#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"


namespace My {
	class Circle : public Shape {
	public:
		//___________________RADIUS____________________________________
		float GetRadius() const { return this->radius; }
		void  SetRadius(float xy) {
			this->radius = xy;
		}
		//__________________________COPY__________________________________
		Circle* Copy() override {
			return new Circle(*this);
		}
		Circle(const Circle& copy) : Circle(copy.GetRadius(), copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}

		//____________________________________________________CONSTRUCTORS_____________________________________________________________
		Circle() :																		  Circle(30.f) {}
		Circle(float radius) :                                                            Circle(radius, {0.f, 0.f}) {}
		Circle(float radius, Vector2f center) :                                           Circle(radius, center, {1.f, 1.f}) {}
		Circle(float radius, Vector2f center, Vector2f scale) :                           Circle(radius, center, scale, 0.f) {}
		Circle(float radius, Vector2f center, Vector2f scale, float angle) :              Circle(radius, center, scale, angle, Color::Cyan) {}
		Circle(float radius, Vector2f center, Vector2f scale, float angle, Color color) : radius(radius), Shape(center, scale, angle, color) {}
		virtual ~Circle() = default;

		//_______________________________________________________DRAW___________________________________________________________________
		void Draw(RenderWindow& window) override {
			CircleShape shape;
			
			shape.setRadius   (this->GetRadius());
			shape.setRotation (this->GetAngle());
			shape.setScale    (this->GetScale());
			shape.setFillColor(this->GetColor());
			if (trans) {
				shape.setFillColor(Color::Transparent);
			}
			if (trail)
			{
				for (auto i : history) {
					shape.setPosition(i.x, i.y);
					window.draw(shape);
				}
			}
			shape.setPosition(this->GetPosition().x, this->GetPosition().y);

			window.draw(shape);
		}
	private: 
		float radius;
	};

}