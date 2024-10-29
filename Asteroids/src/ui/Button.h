#pragma once

#include <string>

#include "raylib.h"

#include "Text.h"

namespace button
{

	const float ButtonWidth = 120;
	const float ButtonHeight = 40;
	const int ButtonFont = 10;

	struct Button
	{
		Rectangle rect;

		text::Text text;

		Color normalColor;
		Color onMouseTopColor;
		Color pressedColor;

		bool isPressed;
		bool isReleased;
		bool isMouseOnTop;
	};

	Button Create(std::string text, Vector2 position, float width = ButtonWidth, float height = ButtonHeight, int fontSize = ButtonFont, Color textColor = BLACK, Color normal = WHITE, Color onTop = GRAY, Color pressed = DARKGRAY);
	Button Create(std::string text, float x, float y, float width = ButtonWidth, float height = ButtonHeight, int fontSize = ButtonFont, Color textColor = BLACK, Color normal = WHITE, Color onTop = GRAY, Color pressed = DARKGRAY);

	Vector2 GetCenterPosition(Button);

	void SetPosition(Button& button, Vector2 newPosition);

	bool MouseOnTop(Button&);
	bool IsPressed(Button&);

	void SetText(Button& button, std::string text);

	void Draw(Button);
}