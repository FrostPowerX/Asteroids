#include "GameManager.h"

namespace game
{
	namespace gamemanager
	{
		int actualScore = 0;
		int maxScore = 0;

		void ResetScore()
		{
			if (actualScore > maxScore)
				maxScore = actualScore;

			actualScore = 0;
		}

		void AddScore(int score)
		{
			actualScore += score;
		}

		int GetScore()
		{
			return actualScore;
		}
		int GetMaxScore()
		{
			return maxScore;
		}
	}
}
