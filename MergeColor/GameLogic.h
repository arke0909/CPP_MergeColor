#pragma once
#include<iostream>

const int Map_HEIGHT = 6;
const int Map_WIDTH = 7;

enum class Block
{
	NONE = '0', OBSTAC = '1', RED = 'r', ORENGE = 'o', YELLOW = 'y',
	GREEN = 'g', BLUE = 'b', PUPLE = 'p'
};

void MoveUpdate(char gameMap[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir);


void MapRender(char gameMap[Map_HEIGHT][Map_WIDTH]);