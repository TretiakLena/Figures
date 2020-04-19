#pragma once
#include <SFML/Graphics.hpp>
#include "Shape.h"

namespace My {
	class Rectangle : public Shape {
	public:
		//________________________________________SIZE______________________________________
		Vector2f GetSize() const { return this->size; }
		void SetSize(Vector2f xy) {
			this->size = xy;
		}
		void SetSize(float xy) {
			this->SetScale(Vector2f(xy, xy));
		}
		//__________________________COPY__________________________________
		Rectangle* Copy() override {
			return new Rectangle(*this);
		}

		//_______________________________________CONSTRUCTORS_____________________________________________________________________________
		Rectangle() :																		  Rectangle(Vector2f(60.f, 60.f)) {}
		Rectangle(Vector2f size) :                                                            Rectangle(size, {0.f, 0.f}) {}
		Rectangle(Vector2f size, Vector2f center) :                                           Rectangle(size, center, {1.f, 1.f}) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale) :                           Rectangle(size, center, scale, 0.f) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale, float angle) :              Rectangle(size, center, scale, angle, Color::Red) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale, float angle, Color color) : size(size), Shape(center, scale, angle, color) {}
		Rectangle(const Rectangle& copy) :                                                    Rectangle(copy.GetSize(), copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}
		virtual ~Rectangle() = default;

		//_______________________________________DRAW_______________________________________________________
		void Draw(RenderWindow& window) override {
			RectangleShape shape;
			
			shape.setSize     (this->GetSize());
			shape.setRotation (this->GetAngle());
			shape.setScale    (this->GetScale());
			shape.setFillColor(this->GetColor());

			if (trans) {
				shape.setFillColor(Color::Transparent);
			}

			if (trail) {
				for (auto i : history) {
					shape.setPosition(i.x, i.y);
					window.draw(shape);
				}
			}
			shape.setPosition(this->GetPosition().x, this->GetPosition().y);
			window.draw(shape);
		}
	private: 
		Vector2f size;
	};
}
