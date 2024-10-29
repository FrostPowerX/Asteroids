#include "ResolutionManager.h"

namespace game
{
	namespace resolutionmanager
	{
		int currentWidth = 1024;
		int currentHeight = 768;

		void Init()
		{
			currentWidth = GetScreenWidth();
			currentHeight = GetScreenHeight();
		}

		Vector2 GetResolution()
		{
			Vector2 res;
			res.x = static_cast<float>(GetScreenWidth());
			res.y = static_cast<float>(GetScreenHeight());

			return res;
		}

		Vector2 GetScale()
		{
			float screenW = static_cast<float>(GetScreenWidth());
			float screenH = static_cast<float>(GetScreenHeight());

			Vector2 scale;
			scale.x = screenW / defaultWidth;
			scale.y = screenH / defaultHeight;

			return scale;
		}

		float GetScalef()
		{
			float screenW = static_cast<float>(GetScreenWidth());
			float screenH = static_cast<float>(GetScreenHeight());

			Vector2 scale;
			scale.x = screenW / defaultWidth;
			scale.y = screenH / defaultHeight;

			float prom = (scale.x + scale.y) / 2;

			return prom;
		}

		void SetResolution(int width, int height)
		{
			currentWidth = width;
			currentHeight = height;

			SetWindowSize(width, height);
		}
	}
}