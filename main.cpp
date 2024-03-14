#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <ctime>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MSSFMLController.h"
using namespace std;


int main() {

    MinesweeperBoard board(5, 5, GameMode::HARD);

    sf::RenderWindow window(sf::VideoMode(800, 600), "MineSweeperBoard");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);
    MSSFMLView view(board);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSSFMLController move(board, view);
    board.debug_display();


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    switch (event.key.code)
                    {
                        case sf::Mouse::Left:
                            move.move_hand(event, window);

                            break;
                        case sf::Mouse::Right:
                            move.move_hand(event, window);
                            break;
                    }
                    break;
            }
        }



        window.clear();
        view.draw(window);
        window.display();

    }

    board.debug_display();

}
/*

    srand(time(NULL));
    //MinesweeperBoard board(5, 5, DEBUG);
    board.debug_display();
    //cout<<board.getMineCount()<<endl;
    //cout<<board.countMines(1,1)<<endl;
    //cout<<board.getFieldInfo(2,3)<<endl;
    //board.revealField(1, 4);
    //board.revealField(2, 4);
    //board.revealField(3, 4);
    //board.debug_display();
    //board.revealField(2, 2);
    //board.debug_display();

    //cout<<board.getGameState()<<endl;
    //cout<<endl<<endl;
    MSBoardTextView view(board);
    view.display();
    MSTextController ctrl(board, view);
    ctrl.play();
    //view.display();
    // ------------------------------------------------ //
    //MSTextController
    //MSTextController ctrl ( board, view);
    //ctrl.play();

}
*/
