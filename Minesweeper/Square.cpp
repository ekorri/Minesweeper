#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(string pValue)
{
	opened = false;
	mined = false;
	flagged = false;
	value = pValue;
}
Square::Square() {
	opened = false;
	mined = false;
	flagged = false;
	value = ".";
}
Square::~Square() {

}
bool Square::getOpened() {
	return opened;
}
void Square::setOpened(bool pOpened) {
	opened = pOpened;
}
bool Square::getMined() {
	return mined;
}
void Square::setMined(bool pMined) {
	mined = pMined;
}
bool Square::getFlagged() {
	return flagged;
}
void Square::setFlagged(bool pFlagged) {
	flagged = pFlagged;
}
void Square::setValue(string pValue) {
	value = pValue;
}
string Square::getValue() {
	return value;
}
ostream& operator <<(ostream& outputStream, const Square& pvalue) {
	string val = pvalue.value;
	outputStream << val;
	return outputStream;
}