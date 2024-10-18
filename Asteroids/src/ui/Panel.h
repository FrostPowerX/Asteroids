#pragma once

#include <string>

#include "raylib.h"

using namespace std;

namespace panel
{
	struct Panel
	{
		Rectangle rect;

		string text;

		Vector2 textPosition;

		float minOffSetX = 0;
		float maxOffSetX = 0;

		float minOffSetY = 0;
		float maxOffSetY = 0;

		int fontSizeText = 0;

		Color rectColor = WHITE;
		Color textColor = WHITE;
	};

	Panel Create(Rectangle rect, string text, float minOffSetX, float maxOffSetX, float minOffSetY, float maxOffSetY, int fontSize, Color rectColor, Color textColor);

	void SetPosition(Panel& panel, Vector2 newPos);
	/// Use this for change text
	void SetText(Panel& panel, string text);
	void SetColorText(Panel& panel, Color color);
	void SetBackGroundColor(Panel& panel, Color color);

	void Draw(Panel);
}

