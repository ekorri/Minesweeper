#include "GameBoard.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ostream>
#include<algorithm>
#include<string>
#include "Square.h"
using namespace std;

GameBoard::GameBoard(int pWidth, int pHeight, int pMines) {
	width = pWidth;
	height = pHeight;
	mines = pMines;
	flags = pMines;
	board = new Square*[height];
	for (int i = 0; i < height; i++) {
		board[i] = new Square[width];
		
	}
}
GameBoard::~GameBoard() {
	for (int i = 0; i < height; i++) {
		delete[] board[i];
	}
	delete[] board;
}


void GameBoard::coutBoard() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << board[i][j];
		}
		cout << "\n" ;
	}
}

int GameBoard::getWidth() {
	return width;
}
int GameBoard::getHeight() {
	return height;
}
int GameBoard::getMines() {
	return mines;
}
int GameBoard::getFlags() {
	return flags;
}
Square GameBoard::getSquare(int x, int y) {
	return board[x][y];
}

void GameBoard::setMines() {
	srand(time(0));
	int i{ 0 };
	while (i < mines) {
		int toBeMinedX = rand() % height;
		int toBeMinedY = rand() % width;
		if (board[toBeMinedX][toBeMinedY].getMined() == false) {
			board[toBeMinedX][toBeMinedY].setMined(true);
			i++;
		}
	}
}
	
	

void GameBoard::showMines() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].getMined() == true) {
				board[i][j].setValue("*");
			}
		}
	}
}

void GameBoard::openSquare(int x, int y) {
	if (x < 0 || x > width - 1 || y < 0 || y > height - 1) {
		return;
	}
	if (board[x][y].getOpened() == true) {
		return;
	}
	if (board[x][y].getFlagged()) {
		return;
	}
	board[x][y].setOpened(true);
	if (board[x][y].getMined() == true) {
		this->showMines();
	}
	if (board[x][y].getMined() == false) {
		this->markNumberValue(x, y);
	}
	if (board[x][y].getMined() == false && this->getSurroundingMines(x, y) == 0) {
		this->markNumberValue(x, y);
		this->openSurroundingSquares(x, y);
	}
}

void GameBoard::flagSquare(int x, int y) {
	if (board[x][y].getFlagged() || board[x][y].getOpened()) {
		return;
	}
	if (flags > 0) {
		board[x][y].setFlagged(true);
		board[x][y].setValue("F");
	}
}

void GameBoard::removeFlag(int x, int y) {
	if (board[x][y].getFlagged() == false) {
		return;
	}
	if (this->flags < this->mines) {
		this->flags++;
	}
	if (board[x][y].getOpened() == true) {
		this->markNumberValue(x, y);
	}
	if (board[x][y].getOpened() == false) {
		board[x][y].setValue(".");
	}
	board[x][y].setFlagged(false);
}

int GameBoard::getSurroundingMines(int x, int y) {
	int startX = max(0, x - 1);
	int startY = max(0, y - 1);
	int endX = min(x + 1, width - 1);
	int endY = min(y + 1, height - 1);
	int counter = 0;

	for (int xi = startX; xi <= endX; xi++) {
		for (int yi = startY; yi <= endY; yi++) {
			if (yi == y && xi == x) {
				continue;
			}
			if (board[xi][yi].getMined() == true) {
				counter++;
			}
		}
	}
	return counter;
}

void GameBoard::markNumberValue(int x, int y) {
	if (this->getSurroundingMines(x, y) == 0) {
		board[x][y].setValue("0");
	}
	else {
		string number = to_string(this->getSurroundingMines(x, y));
		board[x][y].setValue(number);
	}
}

void GameBoard::openSurroundingSquares(int x, int y) {
	int startX = max(0, x - 1);
	int startY = max(0, y - 1);
	int endX = min(x + 1, width - 1);
	int endY = min(y + 1, height - 1);

	for (int xi = startX; xi <= endX; xi++) {
		for (int yi = startY; yi <= endY; yi++) {
			if (board[xi][yi].getOpened() == true) {
				continue;
			}
			if (board[xi][yi].getFlagged() == true) {
				continue;
			}
			if (yi == y && xi == x) {
				continue;
			}
			if (board[xi][yi].getMined() == false) {
				board[xi][yi].setOpened(true);
				this->markNumberValue(xi, yi);
				if (this->getSurroundingMines(xi, yi) == 0) {
					this->openSurroundingSquares(xi, yi);
				}
			}
		}
	}
}

bool GameBoard::allOpened() {
	int allOpened = height * width - mines;
	int counter = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].getOpened()) {
				counter++;
			}
		}
	}
	if (allOpened - counter == 0) {
		return true;
	}
	return false;
}

bool GameBoard::isMinedSquareOpened() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j].getOpened() && board[i][j].getMined()) {
				return true;
			}
		}
	}
	return false;
}

