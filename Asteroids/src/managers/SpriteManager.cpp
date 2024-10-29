#include "SpriteManager.h"

namespace game
{
	namespace spritemanager
	{
		std::vector<Sprite*> sprites;

		void AddSprite(std::string name, std::string path);

		void AddSprite(std::string name, std::string path)
		{
			Sprite* newSp = new Sprite();
			newSp->name = name;
			newSp->texture = LoadTexture(path.c_str());

			sprites.push_back(newSp);
		}

		Sprite* GetSprite(std::string name)
		{
			if (sprites.size() <= 0)
				return nullptr;

			for (int i = 0; i < static_cast<int>(sprites.size()); i++)
			{
				if(name == sprites[i]->name)
					return sprites[i];
			}

			return nullptr;
		}

		void LoadSprites()
		{
			AddSprite("PlayerShip", "res/SpaceShip.png");
			AddSprite("Asteroid", "res/Asteroid.png");
		}

		void UnloadSprites()
		{
			int size = sprites.size();

			for (int i = 0; i < size; i++)
			{
				UnloadTexture(sprites[i]->texture);
			}

			for (int i = 0; i < size; i++)
			{
				delete sprites[i];
			}
		}
	}
}