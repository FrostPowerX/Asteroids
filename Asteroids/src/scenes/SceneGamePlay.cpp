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
				float offset = ButtonHeight * 2.f;
				float posx = currentWidth / 2.f;
				float posy = offset;

				std::string buttonsName[maxButtonsPMenu];

				buttonsName[0] = "Resume";
				buttonsName[1] = "Restart";
				buttonsName[2] = "Menu";

				for (int i = 0; i < maxButtonsPMenu; i++)
				{
					buttonsPMenu[i] = button::Create(buttonsName[i], posx, posy);

					posy += offset;
				}

				posy = offset;

				buttonsName[0] = "Restart";
				buttonsName[1] = "Menu";

				for (int i = 0; i < maxButtonsEMenu; i++)
				{
					buttonsEMenu[i] = button::Create(buttonsName[i], posx, posy);

					posy += offset;
				}
			}

			void InitPanels()
			{
				playerHealth = panel::Create(Rectangle{ 60,30,120,60 }, "", 0, 0, 0, 0, 15, BLACK, WHITE);
				score = panel::Create(Rectangle{ 60,60,120,60 }, "", 0, 0, 0, 0, 15, BLACK, WHITE);
			}

			void CreatePlayer()
			{
				float screenWidth = static_cast<float>(GetScreenWidth());
				float screenHeight = static_cast<float>(GetScreenHeight());

				Rectangle dest{ 0,0,32,32 };

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
				if (CheckBorderCollision(player.body, currentWidth, 0, currentHeight, 0))
				{
					if (player.body.x > currentWidth && player.body.y < currentHeight)
						player.body.x -= currentWidth;
					else if (player.body.x < 0 && player.body.y > 0)
						player.body.x += currentWidth;

					if (player.body.x < currentWidth && player.body.y > currentHeight)
						player.body.y -= currentHeight;
					else if (player.body.x > 0 && player.body.y < 0)
						player.body.y += currentHeight;
				}

				for (int i = 0; i < maxAsteroids; i++)
				{
					Asteroid& ast = GetAsteroid(i);

					if (!ast.isAlive)
						continue;

					if (CheckBorderCollision(ast.body, currentWidth, 0, currentHeight, 0))
					{
						if (ast.body.x > currentWidth && ast.body.y < currentHeight)
							ast.body.x -= currentWidth;
						else if (ast.body.x < 0 && ast.body.y > 0)
							ast.body.x += currentWidth;

						if (ast.body.x < currentWidth && ast.body.y > currentHeight)
							ast.body.y -= currentHeight;
						else if (ast.body.x > 0 && ast.body.y < 0)
							ast.body.y += currentHeight;
					}
				}
			}
		}
	}
}