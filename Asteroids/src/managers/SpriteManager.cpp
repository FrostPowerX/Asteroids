#include "SpriteManager.h"

namespace game
{
	namespace spritemanager
	{
		std::vector<Sprite*> sprites;

		void AddSprite(std::string name, std::string path, bool reescale = true);

		void AddSprite(std::string name, std::string path, bool reescale)
		{
			Sprite* newSp = new Sprite();
			newSp->name = name;
			newSp->texture = LoadTexture(path.c_str());

			if (reescale)
			{
				newSp->texture.width = 32;
				newSp->texture.height = 32;
			}

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
			AddSprite("BackGround", "res/Sprites/BackGround.png");
			AddSprite("PlayerShip", "res/Sprites/SpaceShip.png");
			AddSprite("Cursor", "res/Sprites/Cursor.png");
			AddSprite("Asteroid", "res/Sprites/Asteroid.png");
			AddSprite("Bullet", "res/Sprites/Bullet.png");
			AddSprite("Enemy", "res/Sprites/Enemy.png");
			AddSprite("PowerUp", "res/Sprites/PowerUp.png");
			AddSprite("Button", "res/Sprites/Button.png", false);
			AddSprite("Panel", "res/Sprites/Panel.png", false);
			AddSprite("ScoreBoard", "res/Sprites/ScoreBoard.png", false);
			AddSprite("LinkButton", "res/Sprites/LinkButton.png", false);
			AddSprite("CheckButton", "res/Sprites/CheckButton.png", false);
			AddSprite("Controls", "res/Controls.png", false);
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