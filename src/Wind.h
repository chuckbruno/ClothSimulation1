#pragma once

#include "Vec2.h"
#include "imgui.h"
#include "imgui_impl_sdl.h"


class Wind
{
public:
	static ImVec2 windDirection;
	static float density;
	static Vec2 windPosition;
};
