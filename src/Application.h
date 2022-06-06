#pragma once

#include <vector>
#include <SDL2/SDL.h>


struct Application
{
public:
	Application() = default;
	~Application() = default;

	bool IsRunning() const;

	void Setup(int clothWidth, int clothHeight, int clothSpacing);
	void Input();
	void Update();
	void Render() const;
	void Destroy();

private:
	class Renderer* renderer = nullptr;
	class Mouse* mouse = nullptr;
	class Cloth* cloth = nullptr;

	bool isRunning = false;
	Uint32 lastUpdateTime;
};