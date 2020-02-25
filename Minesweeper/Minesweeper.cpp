// Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Square.h"
#include "GameBoard.h"
using namespace std;

int main()
{
	GameBoard *board = new GameBoard(9, 9, 10);
	board->setMines();
	cout << "Let's start the game" << endl;

	while (true) {
		board->coutBoard();
		cout << "Would you like to open or flag a square? (Y/N) ";
		string reply;
		getline(cin, reply);

		if (reply == "Y" || reply == "y") {
			cout << "Open or flag? (O/F) Or maybe remove a flag? (R) ";
			getline(cin, reply);
			if (reply == "O" || reply == "o") {
				cout << "Give x coordinate ";
				getline(cin, reply);
				int x = stoi(reply);
				cout << "Give y coordinate ";
				getline(cin, reply);
				int y = stoi(reply);
				board->openSquare(y, x);
				Square opened = board->getSquare(y, x);
				if (opened.getMined() == true) {
					board->showMines();
					board->coutBoard();
					cout << "Boom! Game over!";
					break;
				}
				if (board->allOpened()) {
					board->coutBoard();
					cout << "Woohoo! You win!";
					break;
				}
			}
			if (reply == "F" || reply == "f") {
				cout << "Give x coordinate ";
				getline(cin, reply);
				int x = stoi(reply);
				cout << "Give y coordinate ";
				getline(cin, reply);
				int y = stoi(reply);
				board->flagSquare(y, x);
			}
			if (reply == "R" || reply == "r") {
				cout << "Give x coodinate ";
				getline(cin, reply);
				int x = stoi(reply);
				cout << "Give y coordinate ";
				getline(cin, reply);
				int y = stoi(reply);
				board->removeFlag(y, x);
			}
		}
		if (reply == "N" || reply == "n") {
			break;
		}
	}
	board->~GameBoard();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
