#pragma once

#include <string>

namespace input
{
	void AddKey(int key, std::string name);
	void ChangeKey(int newKey, std::string name);
	void RemoveKey(std::string name);

	int GetKey(std::string name);
}