#include "InputManager.h"

#include "raylib.h"

namespace input
{
	struct KeyBinding
	{
		int key;
		std::string name;
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

			keys[i] = defaultKey;
		}
	}

	void AddKey(int key, std::string name)
	{
		KeyBinding newKey;
		newKey.key = key;
		newKey.name = name;

		for (int i = 0; i < maxKeys; i++)
		{
			if (keys[i].key < 0)
				keys[i] = newKey;
		}
	}
	void ChangeKey(int newKey, std::string name)
	{
		for (int i = 0; i < maxKeys; i++)
		{
			if (keys[i].name == name)
				keys[i].key = newKey;
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
			}
		}
	}

	int GetKey(std::string name)
	{
		int key = -1;

		for (int i = 0; i < maxKeys; i++)
		{
			if (keys[i].name == name)
				key = keys[i].key;
		}

		return IsKeyPressed(key);
	}
}
