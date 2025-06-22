#pragma once
#include "GameScene.h"
#include "SelectScene.h"

class SceneManager : public Single<SceneManager>
{
	friend class Single<SceneManager>;

private:
	Scene _curScene = Scene::SELECT;
	Stage _curStage = Stage::NONE;
	int _stageCnt = 10;
	GameData dataArr[10]
	{
		{},

		{1,10,
		"r1000r",
		"010111",
		"010000",
		"000010",
		"111010",
		"r0001r"},
		{2,15,
		"or00or",
		"001010",
		"000100",
		"001010",
		"010000",
		"ro00ro"},

	};
	GameScene _gameScene;
	SelectScene _selectScene = SelectScene(_stageCnt);
	SceneManager(){}
	~SceneManager(){}

public:
	void Init();
	void Update();
	void Render();
};

