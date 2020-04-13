#pragma once
#include <SFML/Graphics.hpp>
// убрал лишние хедеры

using namespace sf;
using namespace std;

namespace My {
	class Main {
	private:
		Main() =  delete;
		~Main() = delete;
	public:
		static constexpr float SPEED = 4.f; //только одним экземпл€ром поэтому static
		static constexpr float ANGLE = 15.f;
		static constexpr float SCALE = 1.f;
		static constexpr int   COLOR = 5;
	};
}