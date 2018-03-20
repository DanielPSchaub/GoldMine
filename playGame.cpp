//Daniel Schaub, Spring 2018
//main file

#include "GoldMine.h"
#include <iostream> 

using namespace std;

int main(){

    GoldMine goldy;

    do{
        goldy.printGoldMine();
        int inRow, inCol;
        do{
        cout << "Please enter the row you wish to search (0 - 5): \n";
        cin >> inRow;
        cout << "Please enter the column you wish to search (0 - 5): \n";
        cin >> inCol;
        } while ( inRow < 0 || inRow > 5 || inCol < 0 || inCol > 5);
        goldy.revealSelection(inRow, inCol);
    }while ( true );
   
    return 0;
}

