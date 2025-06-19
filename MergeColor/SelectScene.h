#pragma once
#include"Enums.h"
const int StageCnt = 10;
void SlectSceneInit(Scene& _eCurScene, Stage& _eCurStage);
void SlectSceneUpdate(Scene& _eCurScene, Stage& _eCurStage);

Stage GetCurSelectStage();
void EnterAnimation();
void SlectSceneRender();
