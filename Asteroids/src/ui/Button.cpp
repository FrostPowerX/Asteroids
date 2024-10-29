#include "Button.h"

#include "managers/ResolutionManager.h"

using namespace game::resolutionmanager;

namespace button
{
	Button Create(std::string text, Vector2 position, float width, float height, int fontSize, Color textColor, Color normal, Color onTop, Color pressed)
	{
		Button newB;

		position.x *= GetScale().x;
		position.y *= GetScale().y;

		newB.rect.width = width * GetScale().x;
		newB.rect.height = height * GetScale().y;
		SetPosition(newB, position);

		newB.text.text = text;
		newB.text.font = static_cast<int>(fontSize * GetScalef());
		newB.text.color = textColor;

		newB.normalColor = normal;
		newB.onMouseTopColor = onTop;
		newB.pressedColor = pressed;

		newB.isMouseOnTop = false;
		newB.isPressed = false;
		newB.isReleased = false;

		SetText(newB, text);

		return newB;
	}

	Button Create(std::string text, float x, float y, float width, float height, int fontSize, Color textColor, Color normal, Color onTop, Color pressed)
	{
		Button newB;

		x *= GetScale().x;
		y *= GetScale().y;

		newB.rect.width = width * GetScale().x;
		newB.rect.height = height * GetScale().y;
		SetPosition(newB, Vector2{ x,y });

		newB.text.text = text;
		newB.text.font = static_cast<int>(fontSize * GetScalef());
		newB.text.color = textColor;

		newB.normalColor = normal;
		newB.onMouseTopColor = onTop;
		newB.pressedColor = pressed;

		newB.isMouseOnTop = false;
		newB.isPressed = false;
		newB.isReleased = false;

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
		button.text.position.x = button.rect.x + (button.rect.width / 2) - (MeasureText(button.text.text.c_str(), button.text.font) / 2);
		button.text.position.y = button.rect.y + (button.rect.height / 2) - (button.text.font / 2);
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

		text::Draw(button.text);
	}
}

