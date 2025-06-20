#pragma once
#include "GameScene.h"
#include "SelectScene.h"

typedef Block BlockMap[Map_HEIGHT][Map_WIDTH];

typedef struct GameDataStruct
{

} GameData, * PGameData;

class SceneManager : public Single<SceneManager>
{
	friend class Single<SceneManager>;

private:
	Scene curScene = Scene::SELECT;
	Stage curStage = Stage::NONE;
	int _stageCnt = 10;
	BlockMap _inGameMapArr[10];
	GameScene _gameScene;
	SelectScene _selectScene = SelectScene(_stageCnt);
	SceneManager(){}
	~SceneManager(){}

public:
	void Init();
	void Update();
	void Render();
};

