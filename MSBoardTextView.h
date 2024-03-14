
#ifndef MAIN_CPP_MSBOARDTEXTVIEW_H
#define MAIN_CPP_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"


class MSBoardTextView {
        MinesweeperBoard &game;
    public:
    MSBoardTextView(MinesweeperBoard &game);
        void display() const;

    };




#endif //MAIN_CPP_MSBOARDTEXTVIEW_H
