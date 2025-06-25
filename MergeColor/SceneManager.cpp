#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	switch (_curScene)
	{
	case Scene::TITLE:
		_selectScene.Update(_curScene, _curStage);
		break;
	case Scene::GAME:
		_gameScene.Update(_curScene ,dataArr[(int)_curStage]);
		break;
	case Scene::QUIT:
		break;
	}
}

void SceneManager::Render()
{
	switch (_curScene)
	{
	case Scene::TITLE:
		_selectScene.Render();
		break;
	case Scene::GAME:
		_gameScene.Render();
		break;
	case Scene::QUIT:
		break;
	case Scene::END:
		break;
	}
}
