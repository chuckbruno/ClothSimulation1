#include "Cloth.h"
#include "Point.h"
#include "Stick.h"
#include "Renderer.h"

#include <iostream>


Cloth::Cloth(int width, int height, int spacing, int startX, int startY)
{
	for (int y = 0; y <= height; ++y)
	{
		for (int x = 0; x <= width; ++x)
		{
			Point* point = new Point(startX + x * spacing, startY + y * spacing);
			if (x != 0)
			{
				Point* leftPoint = points[this->points.size() - 1];
				Stick* s = new Stick(*point, *leftPoint, spacing);
				leftPoint->AddStick(s, 0);
				point->AddStick(s, 0);
				sticks.push_back(s);
			}

			if (y != 0)
			{
				Point* upPoint = points[x + (y - 1) * (width + 1)];
				Stick* s = new Stick(*point, *upPoint, spacing);
				upPoint->AddStick(s, 1);
				point->AddStick(s, 1);
				sticks.push_back(s);
			}

			if (y == 0 && x % 2 == 0)
			{
				point->Pin();
			}

			points.push_back(point);
		}
	}
}

Cloth::~Cloth()
{
	for (auto point : points)
	{
		delete point;
	}

	for (auto stick : sticks)
	{
		delete stick;
	}
}

void Cloth::Update(Renderer* renderer, Mouse* mouse, float deltaTime, float density, ImVec2& wind_direction, Vec2 windPos)
{
	float param = 200000000;
	for (int i = 0; i < points.size(); ++i)
	{
		Point* p = points[i];
		Vec2 pointPos = p->GetPosition();
		float dist = pointPos.Length2(windPos);
		float ratio = 1.0f / dist;
		Vec2 wind{ wind_direction.x * density * param * ratio, wind_direction.y * density * param * ratio };
		Vec2 accelaration = wind + gravity;
		p->Update(deltaTime, drag, accelaration, elasticity, mouse, renderer->GetWindowWidth(), renderer->GetWindowHeight());
	};

	for (int i = 0; i < sticks.size(); ++i)
	{
		Stick* s = sticks[i];
		s->Update();
	}

}

void Cloth::Draw(Renderer* renderer) const
{
	for (int i = 0; i < sticks.size(); ++i)
	{
		sticks[i]->Draw(renderer);

	}
}
