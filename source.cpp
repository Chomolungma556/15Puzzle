#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

static const int BOARD_WIDTH = 4;
static const int BOARD_HEIGHT = 4;
static const int BLANK_NUMBER = 16;

int board[BOARD_HEIGHT][BOARD_WIDTH];

struct Vec2
{
    int x;
    int y;
};

Vec2 getBlankPosition();
void moveBlank(Vec2 argMovePosition);

int main()
{
    for (int y = 0; y < BOARD_HEIGHT; ++y)
    {
        for (int x = 0; x < BOARD_WIDTH; ++x)
        {
            board[y][x] = y * BOARD_HEIGHT + x + 1;
        }
    }

    srand(static_cast<int>(time(NULL)));

    for (int i = 0; i < 1000; ++i)
    {
        Vec2 blankPosition = getBlankPosition();
        Vec2 movePosition = blankPosition;

        switch (rand() % BOARD_HEIGHT)
        {
        case 0:
            ++(movePosition.y);
            break;
        case 1:
            --(movePosition.y);
            break;
        case 2:
            ++(movePosition.x);
            break;
        case 3:
            --(movePosition.x);
            break;
        }

        moveBlank(movePosition);
    }

    while (1)
    {
        system("cls");
        std::cout << "+--+--+--+--+" << std::endl;
        for (int y = 0; y < BOARD_HEIGHT; ++y)
        {
            for (int x = 0; x < BOARD_WIDTH; ++x)
            {
                if (BLANK_NUMBER == board[y][x])
                {
                    std::cout << "|  ";
                }
                else
                {
                    std::cout << "|" << std::setw(2) << board[y][x];
                }
            }
            std::cout << "|" << std::endl;
            std::cout << "+--+--+--+--+" << std::endl;
        }

        bool isClear = true;
        for (int y = 0; y < BOARD_HEIGHT; ++y)
        {
            for (int x = 0; x < BOARD_WIDTH; ++x)
            {
                if (board[y][x] != y * BOARD_HEIGHT + x + 1)
                {
                    isClear = false;
                }
            }
        }

        if (true == isClear)
        {
            std::cout << "Clear!" << std::endl;
        }

        Vec2 blankPosition = getBlankPosition();
        Vec2 movePosition = blankPosition;

        switch (_getch())
        {
        case 'w':
            ++(movePosition.y);
            break;
        case 's':
            --(movePosition.y);
            break;
        case 'a':
            ++(movePosition.x);
            break;
        case 'd':
            --(movePosition.x);
            break;
        }

        moveBlank(movePosition);

    }
    _getch();
    return 0;
}

Vec2 getBlankPosition()
{
    Vec2 blankPosition = { -1, -1 };

    for (int y = 0; y < BOARD_HEIGHT; ++y)
    {
        for (int x = 0; x < BOARD_WIDTH; ++x)
        {
            if (BLANK_NUMBER == board[y][x])
            {
                blankPosition = { x ,y };
            }
        }
    }

    return blankPosition;
}

void moveBlank(Vec2 argMovePosition)
{
    if (argMovePosition.x < 0 || argMovePosition.x >= BOARD_WIDTH || argMovePosition.y < 0 || argMovePosition.y >= BOARD_HEIGHT)
    {
        return;
    }

    Vec2 blankPosition = getBlankPosition();

    // swapping
    int tempBlank = board[blankPosition.y][blankPosition.x];
    board[blankPosition.y][blankPosition.x] = board[argMovePosition.y][argMovePosition.x];
    board[argMovePosition.y][argMovePosition.x] = tempBlank;
}
