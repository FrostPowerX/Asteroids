#include "Ball.h"
#include "..\utilities\Utils.h"

namespace ball
{
	Ball Create(Color color, float x, float y, float radius, float speed)
	{
		Ball newBall = Ball();

		newBall.cir.x = x;
		newBall.cir.y = y;
		newBall.cir.radius = radius;

		newBall.color = color;
		newBall.speed = speed;

		newBall.dirX = (GetRandomValue(-100, 100) / 100.f);
		newBall.dirY = (GetRandomValue(-100, 100) / 100.f);

		float angle = atan2(newBall.dirY, newBall.dirX);

		float minAngleUp = 65.0f * (PI / 180.0f);
		float maxAngleUp = 115.0f * (PI / 180.0f);

		float minAngleDown = 245.0f * (PI / 180.0f);
		float maxAngleDown = 295.0f * (PI / 180.0f);

		if (angle > minAngleUp && angle < maxAngleUp)
			angle = (angle > minAngleUp) ? maxAngleUp : minAngleUp;
		if (angle > minAngleDown && angle < maxAngleDown)
			angle = (angle > minAngleDown) ? maxAngleDown : minAngleDown;

		newBall.dirX = cos(angle);
		newBall.dirY = sin(angle);

		NormalizeVector(newBall.dirX, newBall.dirY);

		newBall.playerId = -1;

		newBall.isActive = false;

		return newBall;
	}

	void Teleport(Ball& ball, float x, float y)
	{
		ball.cir.x = x;
		ball.cir.y = y;
	}

	void Move(Ball& ball)
	{
		if (ball.dirX > 1)
			ball.dirX = 1;
		else if (ball.dirX < -1)
			ball.dirX = -1;

		if (ball.dirY > 1)
			ball.dirY = 1;
		else if (ball.dirY < -1)
			ball.dirY = -1;

		ball.cir.x += ball.dirX * ball.speed * GetFrameTime();
		ball.cir.y += ball.dirY * ball.speed * GetFrameTime();
	}

	void ChangeColor(Ball& circle, Color newColor)
	{
		circle.color = newColor;
	}

	void ChangeRadius(Ball& circle, float newRadius)
	{
		circle.cir.radius = newRadius;
	}

	void ChangeSpeed(Ball& ball, float speed)
	{
		ball.speed = speed;
	}

	void Draw(Ball& ball, int screenWidth, int screenHeight)
	{
		Vector3 pos;
		pos.x = ball.cir.x - screenWidth / 2;
		pos.y = 10;
		pos.z = ball.cir.y - screenHeight / 2;

		DrawSphere(pos, ball.cir.radius, ball.color);
		DrawSphereWires(pos, ball.cir.radius, 3, 2, ball.colorBorder);
	}
}

