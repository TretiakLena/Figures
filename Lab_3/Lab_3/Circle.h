#pragma once
#include <SFML/Graphics.hpp>
// убрал лишние хедеры
#include "Shape.h"

using namespace sf;
using namespace std;


// очевидно, что нужен .cpp
namespace My {
	class Circle : public Shape {
	public:
		//___________________RADIUS____________________________________
		float GetRadius() const { return this->radius; }
		void  SetRadius(float xy) {
			this->radius = xy;
		}

		//____________________________________________________CONSTRUCTORS_____________________________________________________________
		Circle() :																		  Circle(30.f) {}
		Circle(float radius) :                                                            Circle(radius, {0.f, 0.f}) {}
		Circle(float radius, Vector2f center) :                                           Circle(radius, center, {1.f, 1.f}) {}
		Circle(float radius, Vector2f center, Vector2f scale) :                           Circle(radius, center, scale, 0.f) {}
		Circle(float radius, Vector2f center, Vector2f scale, float angle) :              Circle(radius, center, scale, angle, Color::Magenta) {}
		Circle(float radius, Vector2f center, Vector2f scale, float angle, Color color) : radius(radius), Shape(center, scale, angle, color) {} // это просто ќ’”»“≈Ћ№Ќќ!
		virtual ~Circle() = default;

		//_______________________________________________________DRAW___________________________________________________________________
		void Draw(RenderWindow& window) override {
			CircleShape shape;
			shape.setPosition (this->GetPosition().x, this->GetPosition().y);
			shape.setRadius   (this->GetRadius());
			shape.setRotation (this->GetAngle());
			shape.setScale    (this->GetScale());
			shape.setFillColor(this->GetColor());
			window.draw(shape);
		}
	private: 
		float radius;
	};

}