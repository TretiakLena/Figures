#pragma once
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include <vector>
using namespace sf;
using namespace std;

namespace My
{
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
			if(this->trail) this->RememberHistory(this->center);
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
		void SetColor(Color color)               override {
			this->color = color;
		}

		//_________________TRAIL__________________
		virtual void RememberHistory(Vector2f xy) {
			this->history.push_back(xy);
		}
		virtual void SwitchTrail() {
			this->trail = !this->trail;
			this->history.clear();
		}
		virtual void ForgetHistory() {
			if (!this->history.empty()) {
				this->center = this->history[this->history.size() - 1];
				this->history.pop_back();
			}
		}

		//______________________TRANSPARENT_________________________
		virtual void SwitchTrans() {
			this->trans = !this->trans;
		}

		//___________________________COPY____________________________
		virtual Shape* Copy() abstract;
		Shape(const Shape& copy) : Shape(copy.GetPosition(), copy.GetScale(), copy.GetAngle(), copy.GetColor()) {}
		
		//__________________________CONSTRUCTORS______________________________________
		Shape() :                                                          Shape({0.f, 0.f}) {}
		Shape(Vector2f center) :                                           Shape(center, {1.f, 1.f}) {}
		Shape(Vector2f center, Vector2f scale) :                           Shape(center, scale, 0.f) {}
		Shape(Vector2f center, Vector2f scale, float angle) :              Shape(center, scale, angle, Color::Yellow) {}
		Shape(Vector2f center, Vector2f scale, float angle, Color color) : color(color), center(center), scale(scale), angle(angle), trail(false), trans(false) {
			this->RememberHistory(this->center);
		} 
		virtual ~Shape() = default;
	protected:
		Vector2f         center;
		Vector2f         scale;
		float            angle;
		Color            color;
		bool             trail;
		bool             trans;
		vector<Vector2f> history;
	};
}