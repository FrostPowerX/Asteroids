#include "Button.h"

#include "managers/ResolutionManager.h"
#include "managers/SoundManager.h"

using namespace game::resolutionmanager;
using namespace game::soundmanager;

namespace button
{
	Button Create(std::string spriteName, Rectangle dest, std::string text, int fontSize, Color textColor)
	{
		Button newB;

		newB.graph.sprite = GetSprite(spriteName)->texture;

		newB.graph.dest.x = dest.x * GetScale().x;
		newB.graph.dest.y = dest.y * GetScale().y;

		newB.graph.dest.width = dest.width * GetScale().x;
		newB.graph.dest.height = dest.height * GetScale().y;
		SetPosition(newB, Vector2{ dest.x, dest.y });

		newB.graph.origin = Vector2{ 0, 0 };
		newB.graph.source = Rectangle{ 0,0, static_cast<float>(newB.graph.sprite.width), static_cast<float>(newB.graph.sprite.height / 4) };

		newB.text.text = text;
		newB.text.font = static_cast<int>(fontSize * GetScalef());
		newB.text.color = textColor;

		newB.isMouseOnTop = false;
		newB.isPressed = false;
		newB.isReleased = false;

		SetText(newB, text);

		return newB;
	}

	Vector2 GetCenterPosition(Button button)
	{
		Vector2 centerPosition;

		centerPosition.x = button.graph.dest.x + (button.graph.dest.width / 2);
		centerPosition.y = button.graph.dest.y + (button.graph.dest.height / 2);

		return centerPosition;
	}

	void SetPosition(Button& button, Vector2 newPosition)
	{
		button.graph.dest.x = newPosition.x - (button.graph.dest.width / 2);
		button.graph.dest.y = newPosition.y - (button.graph.dest.height / 2);
	}

	bool MouseOnTop(Button& button)
	{
		Vector2 mousePosition = GetMousePosition();

		float minValueX = button.graph.dest.x;
		float minValueY = button.graph.dest.y;

		float maxValueX = button.graph.dest.x + button.graph.dest.width;
		float maxValueY = button.graph.dest.y + button.graph.dest.height;

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
			{
				PlayS("Button");
				isReleassed = true;
			}

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
		button.text.position.x = button.graph.dest.x + (button.graph.dest.width / 2) - (MeasureText(button.text.text.c_str(), button.text.font) / 2);
		button.text.position.y = button.graph.dest.y + (button.graph.dest.height / 2) - (button.text.font / 2);
	}

	void Draw(Button button)
	{
		Rectangle onTop = button.graph.source;
		Rectangle rectPress = button.graph.source;
		Rectangle deactivate = button.graph.source;

		onTop.y += 32;
		rectPress.y += 32 * 2;
		deactivate.y += 32 * 3;

		Rectangle sourceUsed;

		if (button.isPressed)
			sourceUsed = rectPress;
		else if (button.isMouseOnTop)
			sourceUsed = onTop;
		else
			sourceUsed = button.graph.source;

		DrawTexturePro(button.graph.sprite, sourceUsed, button.graph.dest, button.graph.origin, 0, WHITE);

		text::Draw(button.text);
	}
}

