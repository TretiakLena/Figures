#pragma once
#include "Shape.h"
namespace My {
	class Agregat final : public Shape {
	public:
		//____________________________CONSTRUCTORS_____________________________________
		Agregat() : Agregat({}) {}
		Agregat(initializer_list<Shape*> list) : shapes(list), Shape() {
			this->center = this->shapes[0]->GetPosition();
			this->angle = this->shapes[0]->GetAngle();
			this->scale = this->shapes[0]->GetScale();
			this->color = this->shapes[0]->GetColor();
		}
		virtual ~Agregat() {
			for (auto& i : this->shapes) {
				delete i;
			}
		}
		
		//_________________________________COPY____________________________
		Agregat(const Agregat& copy) {
			for (auto i : copy.shapes) {
				this->shapes.push_back(i->Copy());
			}
		}
		Agregat* Copy()                              override {
			return new Agregat(*this);
		}

		//_______________________MOVE_____________________________________
		void SetPosition(Vector2f xy)                override {
			for (auto& i : this->shapes) {
				i->SetPosition(xy);
			}
			this->center = xy;
		}
		void ChangePosition(Vector2f xy)             override {
			for (auto& i : this->shapes) {
				i->ChangePosition(xy);
			}
			this->center += xy;;
		}

		//_____________________________SCALE______________________________
		void ChangeScale(Vector2f xy)                override {
			for (auto& i : this->shapes) {
				i->ChangeScale(xy);
			}
			this->SetScale(this->GetScale() + xy);
		}
		void SetScale(Vector2f xy)                   override {
			for (auto& i : this->shapes) {
				i->SetScale(xy);
			}
			this->scale = xy;
		}

		//_______________________________ANGLE______________________________
		void ChangeAngle(float angle)                override {
			for (auto& i : this->shapes) {
				i->ChangeAngle(angle);
			}
			this->SetAngle(this->GetAngle() + angle);
		}
		void SetAngle(float xy)                      override {
			for (auto& i : this->shapes) {
				i->SetAngle(xy);
			}
			this->angle = xy;
		}

		//___________________________COLOR_____________________________________
		void ChangeColor(int r, int g, int b, int a) override {
			for (auto& i : this->shapes) {
				i->ChangeColor(r, g, b, a);
			}
			if (r < 0 || g < 0 || b < 0 || a < 0) {
				this->SetColor(this->GetColor() - Color(abs(r), abs(g), abs(b), abs(a)));
			}
			else {
				this->SetColor(this->GetColor() + Color(abs(r), abs(g), abs(b), abs(a)));
			}
		}
		void SetColor(Color color)                   override {
			for (auto& i : this->shapes) {
				i->SetColor(color);
			}
			this->color = color;
		}

		//__________________________TRAIL_________________________________________
		void RememberHistory(Vector2f xy)            override {
			for (auto& i : this->shapes) {
				i->RememberHistory(xy);
			}
			this->history.push_back(xy);
		}
		void SwitchTrail()                           override {
			for (auto& i : this->shapes) {
				i->SwitchTrail();
			}
			this->trail = !this->trail;
			this->history.clear();
		}
		void ForgetHistory()                         override {
			for (auto& i : this->shapes) {
				i->ForgetHistory();
			}
			if (!this->history.empty())
			{
				this->center = this->history[this->history.size() - 1];
				this->history.pop_back();
			}
		}

		//__________________________DRAW_______________________________________
		void Draw(RenderWindow& window)              override{
			for (auto& i : this->shapes) {
				i->Draw(window);
			}
		}
	private:
		vector<Shape*> shapes;
	};
}