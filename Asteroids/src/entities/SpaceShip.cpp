#include "SpaceShip.h"

#include "managers/InputManager.h"
#include "utilities/Utils.h"

namespace spaceship
{
	void Move(SpaceShip& sp, Vector2 target);
	void Rotate(SpaceShip& sp, Vector2 target);
	void Shoot(SpaceShip& sp);

	SpaceShip Create(std::string texturePath, Rectangle source, Rectangle dest, Vector2 origin, float speed, float maxSpeed, int lives, bool isAlive)
	{
		return SpaceShip();
	}

	void Move(SpaceShip& sp, Vector2 target)
	{

	}
	void Rotate(SpaceShip& sp, Vector2 target)
	{

	}
	void Shoot(SpaceShip& sp)
	{
		std::cout << "Disparo\n";
	}

	void Update(SpaceShip& sp)
	{
		Move(sp, GetMousePosition());

		if (input::GetKey("Shoot"))
			Shoot(sp);
	}
	void Draw(SpaceShip sp)
	{

	}
}
