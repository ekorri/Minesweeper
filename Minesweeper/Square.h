#pragma once
#include <iostream>
using namespace std;
class Square
{
private:
	bool opened;
	bool mined;
	bool flagged;
	string value;

public:
	Square(string pValue);
	Square();
	~Square();

public:
	bool getOpened();
	void setOpened(bool pOpened);
	bool getMined();
	void setMined(bool pMined);
	bool getFlagged();
	void setFlagged(bool pFlagged);
	void setValue(string pValue);
	string getValue();
	friend ostream& operator <<(ostream& outputStream, const Square& pvalue);

};

