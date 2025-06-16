#pragma once
#include<iostream>
#include "Single.h"

class Block;

const int Map_HEIGHT = 6;
const int Map_WIDTH = 7;

void MoveUpdate(Block inGameBlock[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir);
bool CheckEndMove(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);
void MergeColor(Block& block, Block& target);

void MapRender(Block inGameBlock[Map_HEIGHT][Map_WIDTH]);