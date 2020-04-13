#pragma once
#include <SFML/Graphics.hpp>
// убрал лишние хедеры

using namespace sf;
using namespace std;

struct IMove {
	virtual void ChangePosition(Vector2f xy)	abstract;
	virtual void ChangePosition(float xy)		abstract;
	virtual void SetPosition(Vector2f xy)		abstract;
	virtual void SetPosition(float xy)			abstract;
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