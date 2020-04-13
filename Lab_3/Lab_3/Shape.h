#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Interface.h"
#include "Main.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace sf;
using namespace std;

namespace My
{
	struct IMove {
		virtual void ChangePosition(Vector2f xy) abstract;
		virtual void ChangePosition(float xy)    abstract;
		virtual void SetPosition(Vector2f xy)    abstract;
		virtual void SetPosition(float xy)       abstract;
	};

	struct IDraw {
		virtual void Draw(RenderWindow& window)              abstract;
		virtual void SetColor(Color color)                   abstract;
		virtual void ChangeColor(int r, int g, int b, int a) abstract;
	};

	struct IScale {
		virtual void ChangeScale(Vector2f xy) abstract;
		virtual void ChangeScale(float xy)    abstract;
		virtual void SetScale(Vector2f xy)    abstract;
		virtual void SetScale(float xy)       abstract;
	};

	struct IRotate {
		virtual void ChangeAngle(float xy) abstract;
		virtual void SetAngle(float xy)    abstract;
	};


	class Shape : public IMove, public IDraw, public IScale, public IRotate {
	public:
		//_________________________IMOVE________________________________________
		Vector2f GetPosition() const { return this->center; }
		void ChangePosition(Vector2f xy) override {
			this->SetPosition(this->GetPosition() + xy);
		}
		void ChangePosition(float xy)    override {
			this->ChangePosition(Vector2f(xy, xy));
		}
		void SetPosition(Vector2f xy)    override {
			this->center = xy;
		}
		void SetPosition(float xy)       override {
			this->SetPosition(Vector2f(xy, xy));
		}

		//__________________________ISCALE_______________________________________
		Vector2f GetScale() const { return this->scale; }
		void ChangeScale(Vector2f xy) override {
			this->SetScale(this->GetScale() + xy);
		}
		void ChangeScale(float xy)    override {
			this->ChangeScale(Vector2f(xy, xy));
		}
		void SetScale(Vector2f xy)    override {
			this->scale = xy;
		}
		void SetScale(float xy)       override {
			this->SetScale(Vector2f(xy, xy));
		}

		//___________________________IROTATE______________________________________
		float GetAngle() const { return this->angle; }
		void  ChangeAngle(float angle) override{
			this->SetAngle(this->GetAngle() + angle);
		}
		void  SetAngle(float xy)       override {
			this->angle = xy;
		}
		
		//___________________________COLOR__________________________________________
		Color GetColor()const { return this->color; }		
		void ChangeColor(int r, int g, int b, int a) override {
			if (r < 0 || g < 0 || b < 0 || a < 0){
				this->SetColor(this->GetColor()-Color(abs(r), abs(g), abs(b), abs(a)));
			}
			else{
				this->SetColor(this->GetColor()+Color(abs(r), abs(g), abs(b), abs(a)));
			}
		}
		void SetColor(Color color)                   override {
			this->color = color;
		}

		//__________________________CONSTRUCTORS______________________________________
		Shape() :                                                          Shape(Vector2f(0.f, 0.f)) {}
		Shape(Vector2f center) :                                           Shape(center, Vector2f(1.f, 1.f)) {}
		Shape(Vector2f center, Vector2f scale) :                           Shape(center, scale, 0.f) {}
		Shape(Vector2f center, Vector2f scale, float angle) :              Shape(center, scale, angle, Color::Magenta) {}
		Shape(Vector2f center, Vector2f scale, float angle, Color color) : color(color), center(center), scale(scale), angle(angle) {}
		virtual ~Shape() = default;
	private:
		Vector2f center;
		Vector2f scale;
		float    angle;
		Color    color;
	};
}