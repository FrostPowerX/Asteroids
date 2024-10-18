#include "Button.h"

namespace button
{
	Button Create(std::string text, Vector2 position, float width, float height, int fontSize, Color textColor, Color normal, Color onTop, Color pressed)
	{
		Button newB;

		newB.rect.x = position.x;
		newB.rect.y = position.y;
		newB.rect.width = width;
		newB.rect.height = height;

		newB.text = text;
		newB.fontSize = fontSize;
		newB.textColor = textColor;

		newB.normalColor = normal;
		newB.onMouseTopColor = onTop;
		newB.pressedColor = pressed;

		SetText(newB, text);

		return newB;
	}

	Button Create(std::string text, float x, float y, float width, float height, int fontSize, Color textColor, Color normal, Color onTop, Color pressed)
	{
		Button newB;

		newB.rect.width = width;
		newB.rect.height = height;
		SetPosition(newB, Vector2{ x,y });

		newB.text = text;
		newB.fontSize = fontSize;
		newB.textColor = textColor;

		newB.normalColor = normal;
		newB.onMouseTopColor = onTop;
		newB.pressedColor = pressed;

		SetText(newB, text);

		return newB;
	}

	Vector2 GetCenterPosition(Button button)
	{
		Vector2 centerPosition;

		centerPosition.x = button.rect.x + (button.rect.width / 2);
		centerPosition.y = button.rect.y + (button.rect.height / 2);

		return centerPosition;
	}

	void SetPosition(Button& button, Vector2 newPosition)
	{
		button.rect.x = newPosition.x - (button.rect.width / 2);
		button.rect.y = newPosition.y - (button.rect.height / 2);
	}

	bool MouseOnTop(Button& button)
	{
		Vector2 mousePosition = GetMousePosition();

		float minValueX = button.rect.x;
		float minValueY = button.rect.y;

		float maxValueX = button.rect.x + button.rect.width;
		float maxValueY = button.rect.y + button.rect.height;

		bool onTopX = (mousePosition.x >= minValueX && mousePosition.x <= maxValueX);
		bool onTopY = (mousePosition.y >= minValueY && mousePosition.y <= maxValueY);

		if (onTopX && onTopY)
		{
			button.isMouseOnTop = true;
		}
		else
		{
			button.isMouseOnTop = false;
		}


		return true;
	}

	bool IsPressed(Button& button)
	{
		bool isReleassed = false;

		if (IsMouseButtonReleased(MouseButton::MOUSE_BUTTON_LEFT))
			if (button.isMouseOnTop)
				isReleassed = true;

		if (IsMouseButtonDown(MouseButton::MOUSE_BUTTON_LEFT))
		{
			if (button.isMouseOnTop)
				button.isPressed = true;
			else
				button.isPressed = false;


		}
		else
			button.isPressed = false;

		return isReleassed;
	}

	void SetText(Button& button, std::string text)
	{
		button.textPosition.x = button.rect.x + (button.rect.width / 2) - (MeasureText(button.text.c_str(), button.fontSize) / 2);
		button.textPosition.y = button.rect.y + (button.rect.height / 2) - (button.fontSize / 2);
	}

	void Draw(Button button)
	{
		Color usedColor = WHITE;

		if (button.isPressed)
		{
			usedColor = button.pressedColor;
		}
		else if (button.isMouseOnTop)
		{
			usedColor = button.onMouseTopColor;
		}
		else
			usedColor = button.normalColor;

		DrawRectangleRec(button.rect, usedColor);

		DrawText(button.text.c_str(), static_cast<int>(button.textPosition.x), static_cast<int>(button.textPosition.y), button.fontSize, button.textColor);
	}
}

