#pragma once
#include "GameScene.h"
#include "SelectScene.h"

class SceneManager : public Single<SceneManager>
{
	friend class Single<SceneManager>;

private:
	Scene _curScene = Scene::TITLE;
	Stage _curStage = Stage::NONE;
	int _stageCnt = 10;
	GameData dataArr[11]
	{
		{},

		{1,10,
		"r1000r",
		"010111",
		"010000",
		"000010",
		"111010",
		"r0001r"},
		{2,10,
		"or00or",
		"001010",
		"000100",
		"001010",
		"010000",
		"ro00ro"},
		{3, 10,
		"r1r00r",
		"011100",
		"0p0000",
		"11b110",
		"000000",
		"r0000r"
		},
		{4, 15,
		"r000b0",
		"0100r1",
		"000000",
		"b0010p",
		"000b10",
		"0r1001",
		},
		{5, 15,
		"00r011",
		"0100r0",
		"y110y0",
		"000100",
		"o011y0",
		"10r001",
		},
		{6, 15,
		"0101r0",
		"r0011o",
		"00g010",
		"010000",
		"g10100",
		"0r00y0",
		},
		{7, 15,
		"00001y",
		"r00b00",
		"010101",
		"0p100o",
		"y10g00",
		"0100p0"
		},
		{8, 15,
		"b1g00o",
		"01p10y",
		"000100",
		"0o1001",
		"0y110o",
		"y0ob0r",
		},
		{9, 20,
		"y00r0o",
		"1r1001",
		"001b10",
		"00y110",
		"p10y00",
		"1b01b1",
		},
		{10, 20,
		"o1r001",
		"00101y",
		"p01o00",
		"0gp10b",
		"y10000",
		"1y0r01",
		}
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

