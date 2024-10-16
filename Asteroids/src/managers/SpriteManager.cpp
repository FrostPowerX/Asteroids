#include "SpriteManager.h"

namespace game
{
	namespace spritemanager
	{
		std::vector<Sprite> sprites;

		void AddSprite(std::string name, std::string path)
		{
			Sprite newSp;
			newSp.name = name;
			newSp.texture = LoadTexture(path.c_str());

			sprites.push_back(newSp);
		}

		Sprite GetSprite(std::string name)
		{
			if (sprites.size() <= 0)
				return Sprite();

			for (int i = 0; i < sprites.size(); i++)
			{
				if(name == sprites[i].name)
					return sprites[i];
			}

		}
	}
}