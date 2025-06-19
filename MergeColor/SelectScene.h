#pragma once
#include"Enums.h"
const int StageCnt = 10;
void SlectSceneInit(Scene& eCurScene, Stage& eCurStage);
void SlectSceneUpdate(Scene& eCurScene, Stage& eCurStage);

Stage GetCurSelectStage();
void EnterAnimation();
void SlectSceneRender();
