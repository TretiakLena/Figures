#pragma once
#include <SFML/Graphics.hpp>
// убрал лишние хедеры
#include "Shape.h"

using namespace sf;
using namespace std;

// очевидно, что нужен .cpp
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

		//_______________________________________CONSTRUCTORS_____________________________________________________________________________
		Rectangle() : Rectangle(Vector2f(60.f, 60.f)) {}
		Rectangle(Vector2f size) : size(size) {}
		Rectangle(Vector2f size, Vector2f center) : size(size), Shape(center) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale) : size(size), Shape(center, scale) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale, float angle) : size(size), Shape(center, scale, angle) {}
		Rectangle(Vector2f size, Vector2f center, Vector2f scale, float angle, Color color) : size(size), Shape(center, scale, angle, color) {}
		virtual ~Rectangle() = default;

		//_______________________________________DRAW_______________________________________________________
		void Draw(RenderWindow& window) override {
			RectangleShape shape;
			shape.setPosition(this->GetPosition().x, this->GetPosition().y);
			shape.setSize(this->GetSize());
			shape.setRotation(this->GetAngle());
			shape.setScale(this->GetScale());
			shape.setFillColor(this->GetColor());
			window.draw(shape);
		}
	private: 
		Vector2f size;
	};
}
