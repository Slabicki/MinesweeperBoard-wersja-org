
#ifndef MAIN_CPP_MSTEXTCONTROLLER_H
#define MAIN_CPP_MSTEXTCONTROLLER_H
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "SFML/Graphics.hpp"
#include "MSSFMLView.h"


class MSTextController {
    MinesweeperBoard &Board;
    MSBoardTextView &View;

public:
    MSTextController(MinesweeperBoard &Board, MSBoardTextView &View);
    void play();

};


#endif //MAIN_CPP_MSTEXTCONTROLLER_H
