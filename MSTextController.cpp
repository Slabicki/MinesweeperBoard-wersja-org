#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "MSSFMLView.h"
using namespace std;

MSTextController::MSTextController(MinesweeperBoard &Board, MSBoardTextView&View) : Board(Board),View(View){}

void MSTextController::play() {
    cout << endl << "START GRY" << endl;
    while (Board.getGameState() == RUNNING) {

        cout << endl << "odslon pole - 1" << endl << "ustaw flage - 2" << endl;
        int ruch;
        cout << "ruch: ";
        cin >> ruch;
        int row, col;
        cout << "" << endl;
        cout << "row = ";
        cin >> row;
        cout << endl;
        cout << "col= ";
        cin >> col;

        if(Board.IsBig(row+2,col+2)==false){
           std::cin.clear();
            std::cin.ignore();
            std::cout<<"podano niepoprawny ruch"<<endl;
        }



        if (ruch == 1) {
            Board.revealField(row, col);
        }
        if (ruch == 2) {
            Board.toggleFlag(row, col);
        }

        if (ruch != 1 && ruch != 2) {
            cout << "zly ruch!";
            break;
        }
        View.display();
        cout << endl<<endl;
    }
}
