#pragma once
#include<iostream>
#include "Single.h"
#include "Block.h"

const int Map_HEIGHT = 6;
const int Map_WIDTH = 7;

void MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir);
bool CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
bool CheckEndGame(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);

void MapRender(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);