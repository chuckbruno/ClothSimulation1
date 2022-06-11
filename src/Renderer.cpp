#include <iostream>
#include "Renderer.h"
#include "imgui_impl_sdlrenderer.h"
#include "Wind.h"


Renderer::~Renderer()
{
	// imgui clean up
	ImGui_ImplSDLRenderer_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Renderer::Setup()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error initializing SDL" << std::endl;
		return false;
	}

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	windowWidth = displayMode.w;
	windowHeight = displayMode.h;

	window = SDL_CreateWindow(NULL, 0, 0, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS); // 
	//window = SDL_CreateWindow(NULL, 0, 0, 1280, 720, SDL_WINDOW_BORDERLESS); // 
	if (!window)
	{
		std::cerr << "Error initializing SDL window" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		std::cerr << "Error initializing SDL renderer" << std::endl;
		return false;
	}

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer_Init(renderer);
	return true;
}

void Renderer::ClearScreen(Uint32 color) const
{
	SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderClear(renderer);
}

void Renderer::Render() const
{
	// setup imgui frame
	//ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	//bool show_demo_window = true;
	//bool show_another_window = false;

	//static int counter = 0;

	// create a window and append into it

	ImGui_ImplSDLRenderer_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	//ImGui::SetNextWindowPos(ImVec2(10, 1000));
	//ImGui::SetNextWindowSize(ImVec2(static_cast<float>(100), static_cast<float>(200)));

	ImGui::Begin("Wind Field Panel");                        // Create a window called "Hello, world!" and append into it.

	ImGui::Text("Parameters");               // Display some text (you can use a format strings too)

	ImGui::SliderFloat("Density", &Wind::density, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	ImGui::SliderFloat2("Wind Direction: ", &Wind::windDirection.x, -1, 1);

	//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
	//if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
	//	counter++;
	//ImGui::SameLine();
	//ImGui::Text("counter = %d", counter);

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();

	ImGui::Render();
	//SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
	//SDL_RenderClear(renderer);
	ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());

	SDL_RenderPresent(renderer);
}

void Renderer::DrawLine(int x0, int y0, int x1, int y1, Uint32 color) const
{
	SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
}

void Renderer::DrawPoint(int x, int y, Uint32 color) const
{
	SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}
