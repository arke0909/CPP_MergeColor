#pragma once
#include "GameScene.h"
#include "SelectScene.h"

class SceneManager : public Single<SceneManager>
{
	friend class Single<SceneManager>;

public:
	Scene curScene = Scene::SELECT;
	Stage curStage = Stage::NONE;
private:
	GameScene _gameScene;
	SelectScene _selectScene;
	SceneManager(){}
	~SceneManager(){}

public:
	void Init();
	void Update();
	void Render();
};

