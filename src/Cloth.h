#pragma once

#include <vector>
#include "Vec2.h"


class Cloth
{
public:
	Cloth() = default;
	Cloth(int width, int height, int spacing, int startX, int startY);
	~Cloth();
	void Update(class Renderer* renderer, class Mouse* mouse, float deltaTime, float density, class ImVec2& windDirection, Vec2 windPos);
	void Draw(class Renderer* renderer) const;

private:
	Vec2 gravity = { 0.0f, 981.0f };
	float drag = 0.01f;
	float elasticity = 10.0f;

	std::vector<class Point*> points;
	std::vector<class Stick*> sticks;
};