#pragma once
#include <map>
#include <vector>
#include "InputCommand.h"

// these definitions are in winuser.h but including that generates a number of errors

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F

/*
* VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
* 0x3A - 0x40 : unassigned
* VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
*/

#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D



class GameObject;

// much better here as a class, not a struct
class InputHandler
{	
private:

	GameObject* m_playerCube;
	std::map<int, InputCommand*> m_controlMapping;

public:

	InputHandler(GameObject* playerCube);	// : m_playerCube(playerCube);
	void handleInputs(const std::vector<bool>& keyBuffer);
};
