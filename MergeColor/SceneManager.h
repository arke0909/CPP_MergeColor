#pragma once
#include "GameScene.h"
class SceneManager : public Single<SceneManager>
{
public:
	Scene curScene = Scene::GAME;

private:
	GameScene _gameScene;

public:
	void Update()
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
			break;
		case Scene::END:
			break;
		}
	}
	void Render()
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
			break;
		case Scene::END:
			break;
		}
	}
};

