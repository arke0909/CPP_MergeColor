#pragma once
enum class Key
{
	UP, DOWN, LEFT, SPACE,RIGHT,ESC, FAIL
};
enum class Menu
{
	START, QUIT, FAIL
};
enum class Select
{
	EXIT, RETRY, NEXT, FAIL
};
enum class Scene
{
	TITLE, GAME, QUIT, END
};
enum class BlockType
{
	NONE = '0', OBSTAC = '1', RED = 'r', ORENGE = 'o', YELLOW = 'y',
	GREEN = 'g', BLUE = 'b', PUPLE = 'p'
};
enum class InGameState
{
	NONE = 0, PLAYING = 1, CLEAR = 2, FAIL = 3,
};
enum class Stage
{
	NONE, Stage1 = 1, Stage2, Stage3, Stage4, Stage5, Stage6, Stage7, Stage8, Stage9, Stage10, FAIL
};