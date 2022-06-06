#pragma once

#include "Vec2.h"

class Mouse
{
public:
	Mouse() = default;
	~Mouse() = default;

	const Vec2& GetPosition() const { return pos; }
	const Vec2& GetPreviousPosition() const { return prevPos; }
	void UpdatePosition(int x, int y);

	bool GetLeftButtonDown()const { return leftButtonDown; }
	void SetLeftMouseButton(bool state) { leftButtonDown = state; }

	bool GetRightMouseButton() const { return rightButtonDown; }
	void SetRightMouseButton(bool state) { rightButtonDown = state; }

	void IncreaseCursorSize(float increment);
	float GetCursorSize() const { return cursorSize; }


private:
	Vec2 pos;
	Vec2 prevPos;

	float maxCursorSize = 100;
	float minCursorSize = 20;

	float cursorSize = 20;

	bool leftButtonDown = false;
	bool rightButtonDown = false;

};