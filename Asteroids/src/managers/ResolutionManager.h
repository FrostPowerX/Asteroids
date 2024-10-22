#pragma once

#include "raylib.h"

namespace game
{
	namespace resolutionmanager
	{
		const int defaultWidth = 1024;
		const int defaultHeight = 768;

		extern int currentWidth;
		extern int currentHeight;

		void Init();

		Vector2 GetResolution();
		Vector2 GetScale();
		float GetScalef();

		void SetResolution(Vector2 res);
	}
}