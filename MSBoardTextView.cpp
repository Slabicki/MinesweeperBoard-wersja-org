#include "MSBoardTextView.h"
#include <iostream>
using namespace std;

MSBoardTextView::MSBoardTextView (MinesweeperBoard &game) : game(game){}

void MSBoardTextView::display() const
{
    int height;
    height = game.getBoardHeight();
    int width;
    width = game.getBoardWidth();

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << "[" << game.getFieldInfo(row,col)<<"]";
        }
        cout << endl;
    }
}