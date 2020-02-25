#include "UserInterface.h"
#include "GameBoard.h"
#include "Square.h"
using namespace std;

UserInterface::UserInterface() {
	GameBoard *board = new GameBoard(9, 9, 10);
}
UserInterface::~UserInterface() {

}
void UserInterface::run() {
	board->setMines();

	cout << "Let's start the game" << endl;

	while (true) {
		
		board->coutBoard();
		cout << "Would you like to open or flag a square?" << endl;

		string reply;
		cin >> reply;
	}
}