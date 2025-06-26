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
		{2,15,
		"or00or",
		"001010",
		"000100",
		"001010",
		"010000",
		"ro00ro"},
		{3, 15,
		"r0r00r",
		"011101",
		"0p0000",
		"01b110",
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
		"010010",
		"r00b0y",
		"010101",
		"0p000o",
		"y01g10",
		"0000p0"
		},
		{7, 15,
		"0101r0",
		"r0011o",
		"00g010",
		"010000",
		"g10100",
		"0r00y0",
		},
		{8, 15,
		"b0g000",
		"01p10y",
		"000100",
		"0o0001",
		"0o110p",
		"y0o01r",
		},
		{9, 15,
		"y000p0",
		"1r1001",
		"001010",
		"000110",
		"g10000",
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

