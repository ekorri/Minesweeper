#pragma once
#include <iostream>
#include "Square.h"
#include "GameBoard.h"
using namespace std;

class UserInterface
{
private:
	GameBoard *board;

public:
	UserInterface();
	~UserInterface();
public:
	void run();
};

