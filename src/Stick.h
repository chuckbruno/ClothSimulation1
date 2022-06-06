#pragma once
#include <SDL2/SDL.h>


class Stick
{
public:
	Stick(class Point& p0, class Point& p1, float length);
	~Stick() = default;

	void SetIsSelected(bool value);
	void Update();
	void Draw(const class Renderer* renderer) const;
	void Break();

private:
	class Point& p0;
	class Point& p1;
	float length;

	bool isActive = true;
	bool isSelected = false;

	Uint32 color = 0xFF0048E3;
	Uint32 colorWhenSelected = 0xFFCC0000;
};

