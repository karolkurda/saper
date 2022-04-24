#ifndef MineSweeeperBoard_H__
#define MineSweeeperBoard_H__
#include "Array2D.h"

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    Array2D<Field>board{100, 100};
    int width;
    int height;
    GameMode mode;
    GameState state;
    int UnrevealedCount();
    void moveMine(int r, int c);
    bool firstMove();

public:
    MinesweeperBoard(int height, int width, GameMode mode);
    void debug_display();
    bool is_inside (int row, int col)const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    bool hasMine(int row,int col) const;
    void revealField(int row, int col);
    bool isRevealed(int row, int col);
    char getFieldInfo(int row, int col) const;
    GameState getGameState();
};


#endif
