#pragma once

#include <string>

#include "raylib.h"

#include "managers/SpriteManager.h"
#include "Text.h"

using namespace std;
using namespace game::spritemanager;

namespace panel
{
	struct Panel
	{
		Graphic graph;

		text::Text text;

		float minOffSetX = 0;
		float maxOffSetX = 0;

		float minOffSetY = 0;
		float maxOffSetY = 0;
	};

	Panel Create(string spriteName, Rectangle dest, string text, float minOffSetX = 5, float maxOffSetX = 5, float minOffSetY = 5, float maxOffSetY = 5, int fontSize = 20, Color textColor = WHITE);

	void SetPosition(Panel& panel, Vector2 newPos);
	void SetText(Panel& panel, string text);
	void SetColorText(Panel& panel, Color color);

	void Draw(Panel);
}

