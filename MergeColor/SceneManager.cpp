#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::Init()
{
	char originMapData[Map_HEIGHT][Map_WIDTH]
	{ "r1000r",
	"010111",
	"010000",
	"000010",
	"111010",
	"r0001r" };
	_gameScene.Init(originMapData);
}

void SceneManager::Update()
{
	switch (curScene)
	{
	case Scene::TITLE:
		break;
	case Scene::GAME:
		_gameScene.Update();
		break;
	case Scene::QUIT:
		break;
	case Scene::SELECT:
		_selectScene.Update(curScene, curStage);
		break;
	case Scene::END:
		break;
	}
}

void SceneManager::Render()
{
	switch (curScene)
	{
	case Scene::TITLE:
		break;
	case Scene::GAME:
		_gameScene.Render();
		break;
	case Scene::QUIT:
		break;
	case Scene::SELECT:
		_selectScene.Render();
		break;
	case Scene::END:
		break;
	}
}
