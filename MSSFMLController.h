
#ifndef MAIN_CPP_MSSFMLCONTROLLER_H
#define MAIN_CPP_MSSFMLCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "SFML/Graphics.hpp"
#include "MSSFMLView.h"
#include "MSTextController.h"

class MSSFMLController {
    MinesweeperBoard &Board;
    MSSFMLView &View;
public:
    MSSFMLController(MinesweeperBoard &Board, MSSFMLView &View);
    void move_hand(sf::Event & event, sf::RenderWindow &win);

};


#endif //MAIN_CPP_MSSFMLCONTROLLER_H
