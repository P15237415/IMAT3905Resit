#include "InputHandler.h"
#include <map>
//#include "GameObject.h"
#include <vector>
//#include "TransformComponent.h"
InputHandler::InputHandler(GameObject* playerCube) : m_playerCube(playerCube)
{
	// the idea will be to map the keys directly from a config file that can be loaded in
	// and changed on the fly
	m_controlMapping[(int)'O'] = new RotateLeftCommand();
	m_controlMapping[(int)'P'] = new RotateRightCommand();
	m_controlMapping[(int)'A'] = new MoveForwardCommand();
	m_controlMapping[(int)'Z'] = new MoveBackCommand();
	m_controlMapping[(int)'Q'] = new MoveUpCommand();
	m_controlMapping[(int)'W'] = new MoveDownCommand();
	m_controlMapping[(int)'S'] = new RotateUpCommand();
	m_controlMapping[(int)'X'] = new RotateDownCommand();
	m_controlMapping[32] = new ResetCommand();		//space
	m_controlMapping[(int)'1'] = new CameraFirstCommand();
	m_controlMapping[(int)'2'] = new CameraThirdCommand();

	m_controlMapping[(int)'8'] = new GotoLevel1Command();
	m_controlMapping[(int)'9'] = new GotoLevel2Command();
	m_controlMapping[(int)'0'] = new GotoLevel3Command();

	m_controlMapping[VK_LEFT] = new MoveLeftXYCommand();
	m_controlMapping[VK_RIGHT] = new MoveRightXYCommand();
	m_controlMapping[VK_UP] = new MoveUpXYCommand();
	m_controlMapping[VK_DOWN] = new MoveDownXYCommand();
}

void InputHandler::handleInputs(const std::vector<bool>& keyBuffer)
{
	for (const auto& mapEntry : m_controlMapping)
	{
		if (keyBuffer[mapEntry.first])
		{
			mapEntry.second->execute(*m_playerCube);
		}
	}

}