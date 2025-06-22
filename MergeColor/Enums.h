#pragma once
enum class Key
{
	// W : ΩΩ∂Û¿” on off, e : push on off
	UP, DOWN, LEFT, SPACE,RIGHT,ESC, FAIL
};
enum class Menu
{
	START, QUIT, FAIL
};
enum class Scene
{
	TITLE, GAME, QUIT, SELECT, END
};
enum class BlockType
{
	NONE = '0', OBSTAC = '1', RED = 'r', ORENGE = 'o', YELLOW = 'y',
	GREEN = 'g', BLUE = 'b', PUPLE = 'p'
};
enum class InGameState
{
	NONE = 0, PLAYING = 1, PAUSE = 2, CLEAR = 3, FAIL = 4,
};
enum class Stage
{
	NONE, Stage1 = 1, Stage2, Stage3, Stage4, Stage5, Stage6, Stage7, Stage8, Stage9, Stage10, FAIL
};