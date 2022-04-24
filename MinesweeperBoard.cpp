#include "MinesweeperBoard.h"

#include <iostream>
#include <cstdlib>
#include <ctime>




MinesweeperBoard::MinesweeperBoard (int width, int height, GameMode mode)
{
    this -> width = width;
    this -> height = height;
    this -> mode = mode;

    for (int row=0; row<height; row++)
    {
        for (int column=0; column<width; column++)
        {
            board[row][column] = {false,false,false};
        }
    }

    srand( time( nullptr));
    double mines =0;
    switch(this->mode)
    {
        case EASY:
            mines=height*width*0.1;
            break;
        case NORMAL:
            mines=height*width*0.2;
            break;
        case HARD:
            mines=height*width*0.3;
            break;
        case DEBUG:
            int i = 0;
            while(i<width)
            {
                board[0][i] = {true,false,false};
                board[i][i] = {true,false,false};
                if (i%2==0)board[i][0] = {true,false,false};
                i++;
            }
            break;
    }
    int row; int col;
    int c = height-1; int d= width -1;
    int i =0;
    while(i<mines)
    {
        row=rand()%c;
        col=rand()%d;
        if(board[row][col].hasMine==1) continue;
        else board[row][col].hasMine=true; i++;

    }
}


bool MinesweeperBoard::is_inside (int row, int col) const
{
        if(col < width && row < height && row >= 0 && col >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
}

void  MinesweeperBoard::debug_display()
{
    for(int row=0; row<height; row++)
    {
        for(int column=0; column<width; column++)
        {
            if(board[row][column].hasMine)
                std::cout<< "[M";
            else
                std::cout <<"[.";
            if(board[row][column].isRevealed)
                std::cout<< "o";
            else
                std::cout <<".";
            if(board[row][column].hasFlag)
                std::cout<< "f]";
            else
                std::cout <<".]";
        }
        std::cout <<"\n" <<std::endl;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col)  const
{
    if(board[row][col].hasFlag ==1)
        return true;
    if(!is_inside(row, col))
        return false;
    if(board[row][col].hasFlag ==0)
        return false;
    if(board[row][col].isRevealed ==1)
        return false;
    return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if(!board[row][col].hasFlag)
    {
        board[row][col].hasFlag = true;
    }
    else
    {
        board[row][col].hasFlag = false;
    }
}


bool MinesweeperBoard::isRevealed(int row , int col)
{
    return board[row][col].isRevealed == 1;
}



int MinesweeperBoard::countMines(int row, int col) const
{
    int mines = 0;
    if(is_inside(row,col)== 0)
        return -1;
    if(board[row][col].isRevealed ==0)
        return -1;

    else
    {
        if(is_inside(row-1, col-1) == 1 && board[row-1][col-1].hasMine == 1  )
            mines++;
        if(is_inside(row-1, col) && board[row-1][col].hasMine == 1 )
            mines++;
        if(is_inside(row-1, col+1) && board[row-1][col+1].hasMine == 1 )
            mines++;
        if(is_inside(row, col+1) && board[row][col+1].hasMine == 1 )
            mines++;
        if(is_inside(row, col-1) &&  board[row][col-1].hasMine == 1 )
            mines++;
        if(is_inside(row+1 , col) &&  board[row+1][col].hasMine == 1 )
            mines++;
        if(is_inside(row+1, col+1) &&  board[row+1][col+1].hasMine == 1 )
            mines++;
        if(is_inside(row+1, col-1) &&  board[row+1][col-1].hasMine == 1 )
            mines++;
    }
    return mines;
}

GameState MinesweeperBoard::getGameState() {
return state;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{

    if(!is_inside(row, col))
        return '#';

    if(board[row][col].hasFlag && !board[row][col].isRevealed)
        return 'F';

    if(!board[row][col].hasFlag && !board[row][col].isRevealed)
        return '_';

    if(board[row][col].hasMine && board[row][col].isRevealed)
        return 'x';

    if(board[row][col].isRevealed && countMines(row, col) == 0 )
        return ' ';

    if(board[row][col].isRevealed && countMines(row, col) != 0 )
    {
        return '0' + countMines(row, col);
    }
}


void MinesweeperBoard::revealField(int row, int col)
{
    if(!is_inside(row, col)) return;
    if(getGameState()==FINISHED_WIN) return;
    if(getGameState()==FINISHED_LOSS) return;

    if(isRevealed(row,col)==0 && hasMine(row,col)==1){
        if (UnrevealedCount()==width*height && mode!=DEBUG) {
            moveMine(row,col); board[row][col].isRevealed=true;
        }
        else
        {
            board[row][col].isRevealed=true; state=FINISHED_LOSS;
        }

    }

    else
    {
        if (isRevealed(row, col) || hasFlag(row, col)) {
        return;
        } else if (hasMine(row, col)) {
            isRevealed(row,col);
            state=FINISHED_LOSS;

            //probowalem tutaj zrobic tak, by odkrywalo wszystkie miny przy odkryciu jednej miny, ale niestety nie potrafie
//            if (state=FINISHED_LOSS)
//            for(int row=0;row<height;row++) {
//                for (int col = 0; col < width; col++) {
//                    if (hasMine(row, col)==1)
//                        revealField(row, col);
//
//                }
//            }
        }
        else
        {
            {
                board[row][col].isRevealed = true;
                if(countMines(row, col) == 0)
                {
                    revealField(row, col);
                    revealField(row, col - 1);
                    revealField(row, col + 1);
                    revealField(row - 1, col);
                    revealField(row + 1, col);
                    revealField(row - 1, col - 1);
                    revealField(row + 1, col + 1);
                    revealField(row - 1, col + 1);
                    revealField(row + 1, col - 1);
                }
            }
        }
    }
    if (UnrevealedCount()==getMineCount())
    {
        state=FINISHED_WIN;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}


int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    int mines = 0;
    for(int row=0; row<height; row++)
    {
        for(int column=0; column<width; column++)
        {
            if(board[row][column].hasMine)
                mines +=1;
        }
    }

    return mines;
}

bool MinesweeperBoard::hasMine(int row,int col) const
{
    if(!is_inside(row, col))
    {
        return false;
    }
    else
    {
        if(board[row][col].hasMine == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int MinesweeperBoard::UnrevealedCount() {
    int Unrevealed = 0;
    for(int row=0;row<height;row++)
    {
        for (int col=0;col<width;col++)
        {
            if(!isRevealed(row, col))
            {
                Unrevealed += 1;
            }
            else{}
        }
    }
    return Unrevealed;
}


void MinesweeperBoard::moveMine(int r, int c) {
    if(is_inside(r, c) && hasMine(r, c))
    {
        srand(time(0));
        board[r][c].hasMine = false;
        board[rand() % height][rand() % width].hasMine=true;
    }
};