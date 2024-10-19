#pragma once

#include <string>

namespace input
{
	void Init();

	void AddKey(int key, std::string name, bool isMouse = false);
	void ChangeKey(int newKey, std::string name, bool isMouse = false);
	void RemoveKey(std::string name);

	int GetKey(std::string name);
}