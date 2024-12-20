#include "InputManager.h"

#include "raylib.h"

namespace game
{
	namespace input
	{
		struct KeyBinding
		{
			int key;
			std::string name;

			bool isMouse;
		};

		const int maxKeys = 10;

		KeyBinding keys[maxKeys];

		void Init()
		{
			for (int i = 0; i < maxKeys; i++)
			{
				KeyBinding defaultKey;
				defaultKey.key = -1;
				defaultKey.name = " ";
				defaultKey.isMouse = false;

				keys[i] = defaultKey;
			}

			AddKey(MOUSE_BUTTON_RIGHT, "Move", true);
			AddKey(MOUSE_BUTTON_LEFT, "Shoot", true);
			AddKey(KEY_ESCAPE, "Back");
		}

		void AddKey(int key, std::string name, bool isMouse)
		{
			KeyBinding newKey;
			newKey.key = key;
			newKey.name = name;
			newKey.isMouse = isMouse;

			for (int i = 0; i < maxKeys; i++)
			{
				if (keys[i].key < 0)
				{
					keys[i] = newKey;
					break;
				}
			}
		}
		void ChangeKey(int newKey, std::string name, bool isMouse)
		{
			for (int i = 0; i < maxKeys; i++)
			{
				if (keys[i].name == name)
				{
					keys[i].key = newKey;
					keys[i].isMouse = isMouse;
					break;
				}
			}
		}
		void RemoveKey(std::string name)
		{
			for (int i = 0; i < maxKeys; i++)
			{
				if (keys[i].name == name)
				{
					keys[i].key = -1;
					keys[i].name = " ";
					keys[i].isMouse = false;
					break;
				}
			}
		}

		int GetKeyDown(std::string name)
		{
			int key = -1;
			bool isMouse = false;

			for (int i = 0; i < maxKeys; i++)
			{
				if (keys[i].name == name)
				{
					key = keys[i].key;
					isMouse = keys[i].isMouse;
					break;
				}
			}

			if (isMouse)
				return IsMouseButtonDown(key);

			return IsKeyDown(key);
		}

		int GetKeyPressed(std::string name)
		{
			int key = -1;
			bool isMouse = false;

			for (int i = 0; i < maxKeys; i++)
			{
				if (keys[i].name == name)
				{
					key = keys[i].key;
					isMouse = keys[i].isMouse;
					break;
				}
			}

			if (isMouse)
				return IsMouseButtonPressed(key);

			return IsKeyPressed(key);
		}
	}

}
