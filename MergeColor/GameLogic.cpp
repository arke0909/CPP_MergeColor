#include "GameLogic.h"
#include "Console.h"
using std::cout;


void MoveUpdate(char gameMap[Map_HEIGHT][Map_WIDTH], bool isXMove, int dir)
{
    if (isXMove)
    {
        int start = dir == -1 ? 1 : Map_WIDTH - 2;
        int end = dir == -1 ? Map_WIDTH - 1 : -1;

        for (int i = start; i != end; i -= dir)
        {
            for (int j = 0; j < Map_HEIGHT; j++)
            {
                if (gameMap[j][i] == (char)Block::NONE || gameMap[j][i] == (char)Block::OBSTAC)
                    continue;

                int ni = i;
                while (true)
                {
                    int next = ni + dir;
                    if (next < 0 || next >= Map_WIDTH)
                        break;

                    Block target = (Block)gameMap[j][next];
                    if (target == Block::NONE)
                    {
                        gameMap[j][next] = gameMap[j][ni];
                        gameMap[j][ni] = (char)Block::NONE;
                        ni = next;
                    }
                    else if (target == (Block)gameMap[j][ni])
                    {
                        gameMap[j][next] = (char)Block::NONE;
                        gameMap[j][ni] = (char)Block::NONE;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
    else
    {
        int start = dir == -1 ? 1 : Map_HEIGHT - 2;
        int end = dir == -1 ? Map_HEIGHT : -1;

        for (int i = start; i != end; i -= dir)
        {
            for (int j = 0; j < Map_WIDTH - 1; j++)
            {
                if (gameMap[i][j] == (char)Block::NONE || gameMap[i][j] == (char)Block::OBSTAC)
                    continue;

                int ni = i;
                while (true)
                {
                    int next = ni + dir;
                    if (next < 0 || next >= Map_WIDTH - 1)
                        break;

                    Block target = (Block)gameMap[next][j];
                    if (target == Block::NONE)
                    {
                        gameMap[next][j] = gameMap[ni][j];
                        gameMap[ni][j] = (char)Block::NONE;
                        ni = next;
                    }
                    else if (target == (Block)gameMap[ni][j])
                    {
                        gameMap[next][j] = (char)Block::NONE;
                        gameMap[ni][j] = (char)Block::NONE;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }
}

void MapRender(char gameMap[Map_HEIGHT][Map_WIDTH])
{
	char colorBlock = 'бс';

	for (int i = 0; i < Map_HEIGHT; ++i)
	{
		for (int j = 0; j < Map_WIDTH; ++j)
		{
			if (gameMap[i][j] == (char)Block::OBSTAC)
			{
				SetColor();
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::NONE)
				cout << "  ";
			else if (gameMap[i][j] == (char)Block::RED)
			{
				SetColor(COLOR::RED);
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::ORENGE)
			{
				SetColor(COLOR::LIGHT_RED);
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::YELLOW)
			{
				SetColor(COLOR::YELLOW);
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::GREEN)
			{
				SetColor(COLOR::GREEN);
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::BLUE)
			{
				SetColor(COLOR::BLUE);
				cout << "бс";
			}
			else if (gameMap[i][j] == (char)Block::PUPLE)
			{
				SetColor(COLOR::LIGHT_VIOLET);
				cout << "бс";
			}
		}

		cout << '\n';
	}
	SetColor();
}
