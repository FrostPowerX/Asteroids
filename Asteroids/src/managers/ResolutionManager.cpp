#include "ResolutionManager.h"

namespace game
{
	namespace resolutionmanager
	{
		int currentWidth;
		int currentHeight;

		void Init()
		{
			currentWidth = GetScreenWidth();
			currentHeight = GetScreenHeight();
		}

		Vector2 GetResolution()
		{
			Vector2 res;
			res.x = GetScreenWidth();
			res.y = GetScreenHeight();

			return res;
		}

		Vector2 GetScale()
		{
			float screenW = GetScreenWidth();
			float screenH = GetScreenHeight();

			Vector2 scale;
			scale.x = screenW / defaultWidth;
			scale.y = screenH / defaultHeight;

			return scale;
		}

		float GetScalef()
		{
			float screenW = GetScreenWidth();
			float screenH = GetScreenHeight();

			Vector2 scale;
			scale.x = screenW / defaultWidth;
			scale.y = screenH / defaultHeight;

			float prom = (scale.x + scale.y) / 2;

			return prom;
		}

		void SetResolution(Vector2 res)
		{
			currentWidth = res.x;
			currentHeight = res.y;

			SetWindowSize(res.x, res.y);
		}
	}
}