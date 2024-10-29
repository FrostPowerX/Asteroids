#include "SceneGamePlay.h"

#include <string>

#include "GameLoop.h"

#include "entities/SpaceShip.h"

#include "managers/InputManager.h"
#include "managers/AsteroidsManager.h"
#include "managers/GameManager.h"
#include "managers/ResolutionManager.h"

#include "ui/Button.h"
#include "ui/Panel.h"

#include "utilities/Utils.h"

namespace game
{
	using namespace spaceship;
	using namespace asteroidsmanager;
	using namespace gamemanager;
	using namespace button;
	using namespace panel;
	using namespace resolutionmanager;

	namespace scenes
	{
		namespace gameplay
		{
			const int maxButtonsPMenu = 3;
			const int maxButtonsEMenu = 2;

			SpaceShip player;

			Button buttonsPMenu[maxButtonsPMenu];
			Button buttonsEMenu[maxButtonsEMenu];

			Panel playerHealth;
			Panel score;

			bool endMenu;
			bool pauseMenu;

			void InitButtons();
			void InitPanels();
			void CreatePlayer();

			void Collisions();
			void MapCollisions();

			void Init()
			{
				endMenu = false;
				pauseMenu = false;

				InitButtons();
				InitPanels();

				asteroidsmanager::Init();
				CreatePlayer();

				for (int i = 0; i < 20; i++)
				{
					ActiveAsteroid();
				}
			}

			void Input()
			{
				if (input::GetKeyPressed("Back") && !endMenu)
					pauseMenu = !pauseMenu;

				if (input::GetKeyDown("TripleShoot"))
					player.tripleShoot = !player.tripleShoot;

				if (pauseMenu)
					for (int i = 0; i < maxButtonsPMenu; i++)
					{
						if (IsPressed(buttonsPMenu[i]))
							switch (i)
							{
							case 0:
								pauseMenu = !pauseMenu;
								break;

							case 1:
								ResetScore();
								Init();
								break;

							case 2:
								ResetScore();
								currentScene = SCENE::MENU;
								break;
							}
					}

				if (endMenu)
					for (int i = 0; i < maxButtonsEMenu; i++)
					{
						if (IsPressed(buttonsEMenu[i]))
							switch (i)
							{
							case 0:
								ResetScore();
								Init();
								break;

							case 1:
								ResetScore();
								currentScene = SCENE::MENU;
								break;
							}
					}
			}

			void Update()
			{
				if (!pauseMenu && !endMenu)
				{
					Update(player);

					asteroidsmanager::Update();

					Collisions();
					MapCollisions();

					if (player.lives <= 0)
						endMenu = !endMenu;
				}

				if (pauseMenu)
				{
					for (int i = 0; i < maxButtonsPMenu; i++)
						MouseOnTop(buttonsPMenu[i]);
				}

				if (endMenu)
				{
					for (int i = 0; i < maxButtonsEMenu; i++)
						MouseOnTop(buttonsEMenu[i]);
				}
			}

			void Draw()
			{
				DrawTexturePro(GetSprite("BackGround")->texture,
					Rectangle {
					0, 0, textureWidth, textureHeight
				},
					Rectangle{ 0, 0, static_cast<float>(resolutionmanager::currentWidth), static_cast<float>(resolutionmanager::currentHeight) },
					Vector2{ 0,0 },
					0.f,
					Color{ 100,100,100,255 });

				Draw(player);
				asteroidsmanager::Draw();

				SetText(playerHealth, "Lives " + std::to_string(player.lives));
				SetText(score, "Score " + std::to_string(GetScore()));

				Draw(playerHealth);
				Draw(score);

				if (pauseMenu)
				{
					DrawRectangle(0, 0, currentWidth, currentHeight, Color{ 0,0,0,100 });

					for (int i = 0; i < maxButtonsPMenu; i++)
						Draw(buttonsPMenu[i]);
				}

				if (endMenu)
				{
					DrawRectangle(0, 0, currentWidth, currentHeight, Color{ 0,0,0,100 });

					for (int i = 0; i < maxButtonsEMenu; i++)
						Draw(buttonsEMenu[i]);
				}
			}

			void DeInit()
			{

			}

			void InitButtons()
			{
				float offset = (ButtonHeight * 2.f) * GetScale().y;
				float posx = currentWidth / 2.f;
				float posy = offset;

				std::string buttonsName[maxButtonsPMenu];

				buttonsName[0] = "Resume";
				buttonsName[1] = "Restart";
				buttonsName[2] = "Menu";

				for (int i = 0; i < maxButtonsPMenu; i++)
				{
					buttonsPMenu[i] = button::Create("Button", Rectangle{ posx, posy, ButtonWidth, ButtonHeight }, buttonsName[i]);

					posy += offset;
				}

				posy = offset;

				buttonsName[0] = "Restart";
				buttonsName[1] = "Menu";

				for (int i = 0; i < maxButtonsEMenu; i++)
				{
					buttonsEMenu[i] = button::Create("Button", Rectangle{ posx, posy, ButtonWidth, ButtonHeight }, buttonsName[i]);

					posy += offset;
				}
			}

			void InitPanels()
			{
				playerHealth = panel::Create("Panel", Rectangle{ 64, 32,128,64 }, "");
				score = panel::Create("ScoreBoard", Rectangle{static_cast<float>(currentWidth) / 2, 30,220,60}, "");
			}

			void CreatePlayer()
			{
				float screenWidth = static_cast<float>(GetScreenWidth());
				float screenHeight = static_cast<float>(GetScreenHeight());

				Rectangle dest{ 0,0,64,64 };

				Circle cir;
				cir.x = screenWidth / 2;
				cir.y = screenHeight / 2;
				cir.radius = 15;

				player = Create(cir, dest, "PlayerShip", 500, 500);
			}

			void Collisions()
			{
				for (int i = 0; i < maxAsteroids; i++) // Player to Asteroids Collisions
				{
					if (player.isAlive && GetAsteroid(i).isAlive && CheckCollision(player.body, GetAsteroid(i).body))
					{
						if (player.invencibleT <= 0)
						{
							SolveCollision(player.body, GetAsteroid(i).body);
							DeactiveAsteroid(i);
							TakeDamage(player);
						}
					}
				}

				for (int i = 0; i < maxBullets; i++) // Bullets to Asteroids Collisions
				{
					for (int j = 0; j < maxAsteroids; j++)
					{
						if (GetBullet(player, i).isAlive && GetAsteroid(j).isAlive)
							if (CheckCollision(GetBullet(player, i).body, GetAsteroid(j).body))
							{
								SolveCollision(GetBullet(player, i).body, GetAsteroid(j).body);
								DeactiveAsteroid(j);
								bullet::OnCollision(GetBullet(player, i));
								AddScore(10);
							}
					}
				}
			}
			void MapCollisions()
			{
				if (CheckBorderCollision(player.body, currentWidth + player.body.radius, 0, currentHeight + player.body.radius, 0))
				{
					int minWidth = -player.body.radius;
					int minHeight = -player.body.radius;

					int maxWidth = currentWidth + player.body.radius;
					int maxHeight = currentHeight + player.body.radius;

					if (player.body.x > maxWidth && player.body.y < maxHeight)
						player.body.x -= maxWidth;
					else if (player.body.x < minWidth && player.body.y > minHeight)
						player.body.x += maxWidth;

					if (player.body.x < maxWidth && player.body.y > maxHeight)
						player.body.y -= maxHeight;
					else if (player.body.x > minWidth && player.body.y < minHeight)
						player.body.y += maxHeight;
				}

				for (int i = 0; i < maxAsteroids; i++)
				{
					Asteroid& ast = GetAsteroid(i);

					if (!ast.isAlive)
						continue;

					int minWidth = -ast.body.radius;
					int minHeight = -ast.body.radius;

					int maxWidth = currentWidth + ast.body.radius;
					int maxHeight = currentHeight + ast.body.radius;

					if (CheckBorderCollision(ast.body, maxWidth, minWidth, maxHeight, minHeight))
					{
						if (ast.body.x > maxWidth && ast.body.y < maxHeight)
							ast.body.x -= maxWidth;
						else if (ast.body.x < minWidth && ast.body.y > minHeight)
							ast.body.x += maxWidth;

						if (ast.body.x < maxWidth && ast.body.y > maxHeight)
							ast.body.y -= maxHeight;
						else if (ast.body.x > minWidth && ast.body.y < minHeight)
							ast.body.y += maxHeight;
					}
				}

				for (int i = 0; i < maxBullets; i++)
				{
					bullet::Bullet& bullet = player.bullets[i];

					if (!bullet.isAlive)
						continue;

					int minWidth = -bullet.body.radius;
					int minHeight = -bullet.body.radius;

					int maxWidth = currentWidth + bullet.body.radius;
					int maxHeight = currentHeight + bullet.body.radius;

					if (CheckBorderCollision(bullet.body, maxWidth, minWidth, maxHeight, minHeight))
					{
						if (bullet.body.x > maxWidth && bullet.body.y < maxHeight)
							bullet.body.x -= maxWidth;
						else if (bullet.body.x < minWidth && bullet.body.y > minHeight)
							bullet.body.x += maxWidth;

						if (bullet.body.x < maxWidth && bullet.body.y > maxHeight)
							bullet.body.y -= maxHeight;
						else if (bullet.body.x > minWidth && bullet.body.y < minHeight)
							bullet.body.y += maxHeight;
					}
				}
			}
		}
	}
}