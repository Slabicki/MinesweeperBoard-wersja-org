#include <iostream>
#include "MinesweeperBoard.h"
#include <cstdlib>

using namespace std;


MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)
{

    this->width = width;
    this->height = height;
    int mines;

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            board[row][col].hasMine = false;
            board[row][col].hasFlag = false;
            board[row][col].isRevealed = false;
        }
    }

    switch (mode)
    {
        case EASY:

            mines = 0.1 * width * height;
            for (int licznik = 0; licznik < mines; licznik++)
            {
                int Randheight = rand() % height;
                int Randwidth = rand() % width;
                if (board[Randheight][Randwidth].hasMine)
                    licznik -= 1;
                board[Randheight][Randwidth].hasMine = true;
            }
            break;
        case NORMAL:
            mines = 0.2 * width * height;
            for (int licznik = 0; licznik < mines; licznik++)
            {
                int Randheight = rand() % height;
                int Randwidth = rand() % width;
                if (board[Randheight][Randwidth].hasMine)
                    licznik -= 1;
                board[Randheight][Randwidth].hasMine = true;
            }
            break;
        case HARD:
            mines = 0.3 * width * height;
            for (int licznik = 0; licznik < mines; licznik++)

            {
                int Randheight = rand() % height;
                int Randwidth = rand() % width;
                if (board[Randheight][Randwidth].hasMine)
                    licznik -= 1;
                board[Randheight][Randwidth].hasMine = true;
            }
            break;
        case DEBUG:
            for (int row = 0; row < height; row++)
            {
                for (int col = 0; col < width; col++)
                {
                    if (row == col)
                    {
                        board[row][col].hasMine = true;
                    }
                    if (row == 0) {
                        board[row][col].hasMine = true;
                    }
                    if (col == 0 and row % 2 == 0)
                    {
                        board[row][col].hasMine = true;
                    }

                }
            }
            break;
    }

}

void MinesweeperBoard::debug_display() const
{

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            cout << "[";
            if (board[row][col].hasMine)
                cout << "M";
            else
                cout << ".";
            if (board[row][col].isRevealed)
                cout << "o";
            else
                cout << ".";
            if (board[row][col].hasFlag)
                cout << "f";
            else
                cout << ".";
            cout << "]";
        }
        cout << endl;
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
    int mine=0;
    for(int row=0; row<height; row++)
    {
        for(int col=0; col<width; col++)
        {
            if(board[row][col].hasMine)
                mine++;
        }
    }
    return mine;
}
int MinesweeperBoard::countMines(int row, int col) const
{
    if(row < 0 || row>height || col <0 || col>width)
        return -1;
    //if(isRevealed(row,col))
        //return -1;
    int counter_near_mines=0;
    if(IsBig(row-1, col) && board[row-1][col].hasMine)
        counter_near_mines++;
    if(IsBig(row+1, col) && board[row+1][col].hasMine)
        counter_near_mines++;
    if(IsBig(row, col-1) && board[row][col-1].hasMine)
        counter_near_mines++;
    if(IsBig(row, col+1) && board[row][col+1].hasMine)
        counter_near_mines++;
    if(IsBig(row-1, col+1) && board[row-1][col+1].hasMine)
        counter_near_mines++;
    if (IsBig(row+1, col-1) && board[row+1][col-1].hasMine)
        counter_near_mines++;
    if(IsBig(row+1, col+1) && board[row+1][col+1].hasMine)
        counter_near_mines++;
    if(IsBig(row-1, col-1) && board[row-1][col-1].hasMine)
        counter_near_mines++;
    return counter_near_mines;
}
bool MinesweeperBoard::IsBig(int row, int col)const
{
    if(row < 0 || row>height+1 || col <0 || col>width+1)
    {
        return false;
    }
    return true;
}
bool MinesweeperBoard::hasFlag(int row, int col)const {
    if (!IsBig(row, col)) {
        return false;
    }
    if (board[row][col].hasFlag) {
        return true;
    }
    if(!board[row][col].hasFlag)
        return false;
    if(board[row][col].isRevealed)
        return false;
    else
    {
    return false;
    }
}

void MinesweeperBoard::toggleFlag(int row, int col){
    if (!IsBig(row, col)) {
        return;
    }
    if (board[row][col].isRevealed == 1)
        return;
    if (getGameState() != RUNNING) {
        cout << "KONIES GRY-WYGRANA" << endl;
        return;
    }
    if(!board[row][col].isRevealed && !board[row][col].hasFlag)
    {
        board[row][col].hasFlag = true;
    }
}
void MinesweeperBoard::removeFlag(int row, int col) {
    if (row < 0 || row > height || col < 0 || col > width)
    {
        return;
    }
    if (board[row][col].isRevealed == 1)
    {
        return;
    }

    if(getGameState()!= RUNNING)
    {
        cout << "KONIEC" << endl;
        return;
    }
    if(board[row][col].hasFlag){
        board[row][col].hasFlag = false;

    }
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (board[row][col].isRevealed == 1)
    {
        return;
    }

    if(getGameState()!= RUNNING)
    {
        cout << "KONIEC" << endl;
        return;
    }
    if (row < 0 || row > height || col < 0 || col > width)
    {
        return;
    }
    if (board[row][col].hasFlag == 1)
    {
        return;
    }

    if(!board[row][col].isRevealed && !board[row][col].hasMine){
        board[row][col].isRevealed = true;
    }

    if(!board[row][col].isRevealed && board[row][col].hasMine)
    {
        if(First_Move == true && mode != DEBUG){
            First_Move = false;
            board[row][col].hasMine = false;
            board[row][col].isRevealed = true;
            Create_NewMine();
            return;
        }
        board[row][col].isRevealed = true;
        cout << "KONIEC GRY-PRZEGRANA" << endl;
        getGameState();

    }
    First_Move = false;


    if (countMines(row, col) != 0) return;
    revealField(row-1, col);
    revealField(row, col-1);
    revealField(row+1, col);
    revealField(row, col+1);
    revealField(row-1, col-1);
    revealField(row-1, col+1);
    revealField(row+1, col-1);
    revealField(row+1, col+1);

}

bool MinesweeperBoard::isRevealed(int row, int col)const
{

    if(board[row][col].isRevealed ==true)
    {
        return true;
    }
    return false;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(row>height or col>width or row <0 or col<0)
        return '#';
    if(!isRevealed(row,col) and hasFlag(row,col))
        return 'F';
    if(!isRevealed(row,col) and !hasFlag(row,col))
        return '_';
    if(isRevealed (row, col) and board[row][col].hasMine)
        return 'x';
    if(isRevealed(row, col) and countMines(row,col) == 0)
        return ' ';
    if(isRevealed(row,col) and countMines(row,col) !=0)
        return '0'+ countMines(row,col);
        //return char(countMines(row, col)+'2');
    return 0;
}

GameState MinesweeperBoard::getGameState() const {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (board[row][col].isRevealed && board[row][col].hasMine) {
                return FINISHED_LOSS;
            }
        }
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (!board[row][col].isRevealed && !board[row][col].hasMine) {
                goto exit;
            }
        }
    }
    return FINISHED_WIN;
    exit:
    return RUNNING;
}
/*
GameState MinesweeperBoard::getGameState() const {
    int Free_field_counter = 0;
    int Flag = 0;
    for (int row = 0; row > getBoardHeight(); row++) {
        for (int col = 0; col > getBoardWidth(); col++) {
            if (board[row][col].isRevealed && board[row][col].hasMine)
                return FINISHED_LOSS;
            if (!board[row][col].hasMine && isRevealed(row, col))
                Free_field_counter++;
            if (!board[row][col].hasMine && hasFlag(row, col))
                Flag++;
            if (board[row][col].hasFlag && board[row][col].isRevealed)
                return FINISHED_WIN;

        }
    }
    return RUNNING;
}
*/
void MinesweeperBoard::Create_NewMine(){

    int row = rand() % height;
    int col = rand() % width;

    if(!board[row][col].hasMine){
        board[row][col].hasMine = true;
    } else {
        Create_NewMine();
    }
}

bool MinesweeperBoard::hasMine(int row, int col) const{

    if (row < 0 || row > height || col < 0 || col > width)
    {
        return false;
    }
    if(board[row][col].isRevealed == true)
    {
        return true;
    }
    if(board[row][col].hasMine) {
        return true;
    }
    else
    {
        return false;
    }

}