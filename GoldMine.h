//Daniel Schaub, Spring 2018
#ifndef GOLDMINEH
#define GOLDMINEH

#include <string>
#include "twoDim.h"

class GoldMine{
 public:
    GoldMine();
    void resetGame();
    void randomRowColumn(int &row, int &column);
    std::string rainbowMessage();
    void revealSelection(int row, int column);
    void printGoldMine();
    int getGold();
    void setGoldLocation(int row, int column);
    void playAgain();
 private:
    twoDim<bool> visited; //create the array of boxes, *'s
    twoDim<char> boxType; //-'s G's R's C's
    twoDim<int> goldAmount; //lost per grid
    int gold; //holds the inital amount of gold 1000-9000
    int goldRow;
    int goldCol;
    int seed; 
};

#endif
