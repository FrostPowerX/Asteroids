#ifndef BUTTON
#define BUTTON

#include <string>

#include "raylib.h"

const float ButtonWidth = 120;
const float ButtonHeight = 40;
const int ButtonFont = 10;

struct Button
{
	Rectangle rect;

	std::string text;

	Vector2 textPosition;

	Color normalColor;
	Color onMouseTopColor;
	Color pressedColor;

	Color textColor;

	int fontSize;

	bool isPressed;
	bool isReleased;
	bool isMouseOnTop;
};

Button CreateButton(std::string text, Vector2 position, float width = ButtonWidth, float height = ButtonHeight, int fontSize = ButtonFont, Color textColor = BLACK, Color normal = WHITE, Color onTop = GRAY, Color pressed = DARKGRAY);
Button CreateButton(std::string text, float x, float y, float width = ButtonWidth, float height = ButtonHeight, int fontSize = ButtonFont, Color textColor = BLACK, Color normal = WHITE, Color onTop = GRAY, Color pressed = DARKGRAY);

Vector2 GetCenterPositionButton(Button);

void SetButtonPosition(Button& button, Vector2 newPosition);

bool MouseOnTopButton(Button&);
bool IsButtonPressed(Button&);

void SetText(Button& button, std::string text);

void DrawButton(Button);

#endif // !BUTTON
