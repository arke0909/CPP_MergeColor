#pragma once
enum class Key
{
	// W : ΩΩ∂Û¿” on off, e : push on off
	UP, DOWN, LEFT, RIGHT,ESC, FAIL
};
enum class Menu
{
	START, QUIT, FAIL
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
	NONE = 0, PLAYING = 1, CLEAR = 2
};