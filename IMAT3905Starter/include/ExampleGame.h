#pragma once
#include "Game.h"

class ModelManager;

class ExampleGame : public Game
{
public:
	ExampleGame(IEngineCore* engine);
	void update(float dt) override;
	void render() override;
	void Initialise();


	virtual void imguiInit();
	virtual void imguiRender();
	virtual void imguiShutdown();

private:

	ModelManager* m_theModelManager;
	int m_sceneIndex{ 0 };
	//these could be loaded from a file...
	std::string m_levelNames[3] = {
		"assets/levels/testLevel.json",
		"assets/levels/testLevel2.json",
		"assets/levels/testLevel3.json"
	};
};
