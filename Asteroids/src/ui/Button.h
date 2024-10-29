#pragma once

#include <string>

#include "raylib.h"

#include "managers/SpriteManager.h"

#include "Text.h"

using namespace game::spritemanager;

namespace button
{
	const float ButtonWidth = 180;
	const float ButtonHeight = 80;
	const int ButtonFont = 20;

	struct Button
	{
		text::Text text;

		Graphic graph;

		bool isPressed;
		bool isReleased;
		bool isMouseOnTop;
	};

	Button Create(std::string spriteName, Rectangle dest = {0,0,ButtonWidth, ButtonHeight}, std::string text = "example", int fontSize = ButtonFont, Color textColor = BLACK);

	Vector2 GetCenterPosition(Button);

	void SetPosition(Button& button, Vector2 newPosition);

	bool MouseOnTop(Button&);
	bool IsPressed(Button&);

	void SetText(Button& button, std::string text);

	void Draw(Button);
}