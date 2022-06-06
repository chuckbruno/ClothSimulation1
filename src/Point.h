#pragma once
#include "Vec2.h"

class Point
{
public:
	Point() = default;
	Point(float x, float y);
	~Point() = default;

	void AddStick(class Stick* stick, int index);
	const Vec2& GetPosition() const { return pos; }
	void SetPosition(float x, float y);

	void Pin();
	void Update(float deltaTime, float drag, const Vec2& acceleration, float elasticity, class Mouse* mouse, int windowWidth, int windowHeight);

private:
	class Stick* sticks[2] = { nullptr };
	Vec2 pos;
	Vec2 prePos;
	Vec2 initPos;

	bool isPinned = false;
	bool isSelected = false;
	void KeepInsideView(int width, int height);
};