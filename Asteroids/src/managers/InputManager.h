#pragma once

#include <string>

namespace game
{
	namespace input
	{
		void Init();

		void AddKey(int key, std::string name, bool isMouse = false);
		void ChangeKey(int newKey, std::string name, bool isMouse = false);
		void RemoveKey(std::string name);

		int GetKeyDown(std::string name);
		int GetKeyPressed(std::string name);
	}
}
