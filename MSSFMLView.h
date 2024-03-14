#ifndef MAIN_CPP_MSSFMLVIEW_H
#define MAIN_CPP_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"


class MSSFMLView {
    MinesweeperBoard & board;
    sf::Font font;
    sf::Text mines;
    sf::RectangleShape field;

public:
    explicit MSSFMLView(MinesweeperBoard & b);
    void draw (sf::RenderWindow & win);
    void Win (sf::RenderWindow & win);
};


#endif
