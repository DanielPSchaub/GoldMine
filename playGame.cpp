//Daniel Schaub, Spring 2018
//main file

#include "GoldMine.h"
#include <iostream> 
#include <limits>

using namespace std;

int main(){

    GoldMine goldy;

    do{
        goldy.printGoldMine();
        int inRow, inCol;
        do{
        cout << "Please enter the row you wish to search (0 - 5): \n";
        cin >> inRow;
        if (cin.fail()){ //input validation
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inRow = -1;
        }
        cout << "Please enter the column you wish to search (0 - 5): \n";
        cin >> inCol;
        if (cin.fail()){ //input validation
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inCol = -1;
        }
        } while ( inRow < 0 || inRow > 5 || inCol < 0 || inCol > 5);
        goldy.revealSelection(inRow, inCol);
    }while ( true );
   
    return 0;
}

