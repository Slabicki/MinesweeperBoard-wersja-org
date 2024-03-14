#include <iostream>
#include <cstdlib>
#include "MSSFMLController.h"


using namespace std;

MSSFMLController::MSSFMLController(MinesweeperBoard &Board, MSSFMLView &view) : Board(Board), View(view){}
void MSSFMLController::move_hand(sf::Event &event, sf::RenderWindow &win) {

    if (event.type == sf::Event::MouseButtonPressed){


        int col = ((event.mouseButton.x - 300)/40);
        int row = ((event.mouseButton.y - 140)/40);

        if(event.mouseButton.button == sf::Mouse::Left){
            cout << "Left button: " << event.mouseButton.button << endl;
            cout << "X: " << event.mouseButton.x << endl;
            cout << "Y: " << event.mouseButton.y << endl;
            Board.revealField(row, col);

            return;

        }

        if(event.mouseButton.button == sf::Mouse::Right){
            cout << "Right button: " << event.mouseButton.button << endl;
            cout << "X: " << event.mouseButton.x << endl;
            cout << "Y: " << event.mouseButton.y << endl;


            if(Board.getFieldInfo(row, col) == 'F') {
                Board.removeFlag(row, col);
            }
            else {
                Board.toggleFlag(row, col);
            }
        }

    }

};
