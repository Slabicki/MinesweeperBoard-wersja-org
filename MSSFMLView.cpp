#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <cstring>




MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {}

void MSSFMLView::draw (sf::RenderWindow & win) {


    sf::Font font;
    if(!font.loadFromFile("../font/Montserrat-Light.ttf"))
        return;

    sf::RectangleShape field;
    field.setSize(sf::Vector2f(35, 35));


    sf::Text mines;
    mines.setFont(font);
    mines.setCharacterSize(28);
    mines.setFillColor(sf::Color::White );



    int x = 0;
    int y = 0;

    for(int row=0; row<board.getBoardHeight(); row++) {
        x = 0;
        for(int col=0; col<board.getBoardWidth(); col++){
            char h = board.getFieldInfo(row, col);

            switch(h) {
                case 'F': {
                    field.setFillColor ( sf::Color::Green);
                    field.setPosition(300 + x, 140 + y);
                    win.draw(field);
                    x = x + 40;
                    break;
                }
                case 'x' : {
                    board.revealField(row, col);
                    field.setFillColor ( sf::Color::Red);
                    field.setPosition(300 + x, 140 + y);
                    win.draw(field);
                    x = x + 40;
                    break;
                }

                case ' ' : {
                    field.setFillColor(sf::Color::Blue);
                    field.setPosition(300 + x, 140 + y);
                    win.draw(field);
                    x = x + 40;
                    break;
                }

                case '1' :
                case '2' :
                case '3' :
                case '4' :
                case '5' :
                case '6' :
                case '7' :
                case '8' :
                case '9' :
                {
                    field.setFillColor ( sf::Color::Blue );
                    field.setPosition(300 + x, 140 + y);
                    win.draw(field);

                    mines.setPosition(300 + x, 140 + y);
                    mines.setString(board.getFieldInfo(row, col));
                    win.draw(mines);

                    x = x + 40;

                    break;
                }

                case '_' : {
                    field.setFillColor ( sf::Color::White);
                    field.setPosition(300 + x, 140 + y);
                    win.draw(field);
                    x = x + 40;
                    break;
                }

            }
        }
        y = y + 40;
    }
 Win(win);
}
void MSSFMLView::Win  (sf::RenderWindow &win) {
    GameState status = board.getGameState();
    sf::Text text;
    if(!font.loadFromFile("../Font/Montserrat-Light.ttf"))
        return;
    switch (status)
    {
        case FINISHED_WIN:
            text.setString("WIN!");
            text.setFillColor(sf::Color::Green);
            text.setPosition(350,50);
            break;
        case FINISHED_LOSS:
            text.setString("DEFEAT!");
            text.setFillColor(sf::Color::Red);
            text.setPosition(330,50);
            break;
        case RUNNING:
            text.setString("HAVE FUN!");
            text.setFillColor(sf::Color::Blue);
            text.setPosition(310,50);
    }
    text.setFont(font);
    text.setCharacterSize(30);
    win.draw(text);
}












































