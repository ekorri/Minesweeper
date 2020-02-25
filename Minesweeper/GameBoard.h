#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Square.h"
using namespace std;

class GameBoard
{
private:
	int width;
	int height;
	int mines;
	int flags;
	Square** board;

public:
	GameBoard(int pWidth, int pHeight, int pMines);
	~GameBoard();

public:
	void coutBoard();
	int getWidth();
	int getHeight();
	int getMines();
	int getFlags();
	Square getSquare(int x, int y);
	void setMines();
	void showMines();
	void openSquare(int x, int y);
	void flagSquare(int x, int y);
	void removeFlag(int x, int y);
	int getSurroundingMines(int x, int y);
	void markNumberValue(int x, int y);
	void openSurroundingSquares(int x, int y);
	bool allOpened();
	bool isMinedSquareOpened();
};

