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
		break;
	case Scene::GAME:
		_gameScene.Update(dataArr[(int)_curStage]);
		break;
	case Scene::QUIT:
		break;
	case Scene::SELECT:
		_selectScene.Update(_curScene, _curStage);
		break;
	case Scene::END:
		break;
	}
}

void SceneManager::Render()
{
	switch (_curScene)
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
