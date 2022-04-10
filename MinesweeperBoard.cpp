#include "MinesweeperBoard.h"
#include "Array2D.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
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

    srand( time( NULL ) );
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
            int tmp = 0;
            while(tmp<width)
            {
                board[0][tmp] = {1,0,0};
                board[tmp][tmp] = {1,0,0};
                if (tmp%2==0)
                    board[tmp][0] = {1,0,0};

                tmp ++;
            }
            break;

    }

    int row =0; int col=0;
    int c = height-1; int d= width -1;
    int i =0;

    while(i<mines)
    {
        row=rand()%c;
        col=rand()%d;

        if(board[row][col].hasMine==1)
        {
            continue;
        }

        else
        {
            board[row][col].hasMine=true;
            i++;
        }
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

void  MinesweeperBoard::debug_display() const
{
    for(int row=0; row<height; row++)
    {
        for(int column=0; column<width; column++)
        {
            if(board[row][column].hasMine == true)
                cout<< "[M";
            else
                cout <<"[.";
            if(board[row][column].isRevealed == true)
                cout<< "o";
            else
                cout <<".";
            if(board[row][column].hasFlag == true)
                cout<< "f]";
            else
                cout <<".]";
        }
        cout <<"\n" <<endl;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col)  const //?????
{

    if(board[row][col].hasFlag ==1)
        return true;
    if(!is_inside(row, col))
        return false;
    if(board[row][col].hasFlag ==0)
        return false;
    if(board[row][col].isRevealed ==1)
        return false;

}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    board[row][col].hasFlag = true;
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
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(isRevealed(row, col)==1 && board[row][col].hasMine==1) return FINISHED_LOSS;
        }
    }
    int other=0;
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(board[row][col].hasMine==0 && board[col][row].isRevealed==0) other++;
        }
    }
    if (other==0) return FINISHED_WIN;
    return RUNNING;
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

bool MinesweeperBoard::firstMove()
{
    for(int row=0; row < height; row++)
    {
        for(int col=0; col <width; width++)
        {
            if(board[row][col].hasFlag ==1 || board[row][col].isRevealed==1)
                return false;

        }
    }
    return true;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if(is_inside(row, col) == false)
    {
        std::cout << "\n -- YOU'RE OUT OF THE BOARD!!! -- \n";
        return;
    }
    else
    {
        if (isRevealed(row, col) || hasFlag(row, col)) {

        } else if (hasMine(row, col)) {
            std::cout << std::endl;
            std::cout << "\n--------------------------------------------------";
            std::cout << "\nYou stomp on mine, gg ez report my team";
            std::cout << "\n--------------------------------------------------";
            std::cout << std::endl;
            exit(EXIT_SUCCESS);
        }
        else {
            {
                std::cout << std::endl;
                std::cout << "\n--------------------------------------------------";
                std::cout << "\nWell done";
                std::cout << "\n--------------------------------------------------";
                std::cout << std::endl;

                board[row][col].isRevealed = true;
            }
        }
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
            if(board[row][column].hasMine == true)
                mines +=1;
        }
    }

    return mines;
}

bool MinesweeperBoard::hasMine(int row,int col) const
{
    if(is_inside(row,col) == false)
        return false;
    if(board[row][col].hasMine ==1)
        return true;
    return false;
}