#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace My {
	class Main {
	private:
		Main() =  delete;
		~Main() = delete;
	public:
		static constexpr float SPEED = 4.f; //������ ����� ����������� ������� static
		static constexpr float ANGLE = 5.f;
		static constexpr float SCALE = 1.f;
		static constexpr int   COLOR = 5;
	};
}