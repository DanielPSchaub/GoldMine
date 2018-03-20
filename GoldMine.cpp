//Daniel Schaub, Spring 2018
#include "GoldMine.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

GoldMine::GoldMine(){
    resetGame();
}

void GoldMine::resetGame(){ 
    //initialize inital gold
    seed++;
    srand(seed);
    this->gold = rand() % 8000 + 1000;

    //initialize visited to all FALSE
    for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            visited.setElement(i, j, false);   
    }   
    
    //initialize boxType to all '-'
    for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            boxType.setElement(i, j, '-');   
    }
    
    //make some random locations i = row, G = gold, C = coal, R = rainbow
    int iG, iC, iR, jG, jC, jR;
    iG = rand() % 6;
    iC = rand() % 6;
    iR = rand() % 6;
    jG = rand() % 6;
    do{ //ensure they're not on top of each other, in a non-efficient, but practical, way
    jC = rand() % 6;
    jR = rand() % 6;
    } while (jC == jG || jR == jG);
    boxType.setElement(iG, jG, 'G');
    boxType.setElement(iC, jC, 'C');
    boxType.setElement(iR, jR, 'R');
    
    setGoldLocation(iG, jG);

    //make random amounts for gold loss
    for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            goldAmount.setElement(i, j, rand()%90+10);   
    }

    //Opening Messages:
    cout << "Welcome to the wide happy world of Alcohol World!\n";
    cout << "You've just been badly poisoned and only the fabled Aqua Tequila will save you. Now journey on and find it!\n";
    cout << "You start with: " << getGold() << " sobriety! Don't let it run out or you'll be trapped here, in drunk hell, forever.\n"; 
} // end resetGame()

void GoldMine::randomRowColumn(int &row, int &column){
    row = rand() % 6;
    column = rand() % 6;
}

string GoldMine::rainbowMessage(){
    string fluff = "The rainbow attracted a drunk Irishman! He grabs you close and breaths deep into your ear.\nWhooosh. He tells you in a sweaty, whiskey breath: You'll find the blessed Aqua Tequila in the ";
    string updown;
    string leftright;
    if ( goldRow < 2 ){
        updown = "UPPER ";
    } else if ( goldRow > 3 ) {
        updown = "LOWER ";
    } else if (goldRow == 2 || goldRow == 3){
        updown = "CENTER ";
    }
    
    if ( goldCol < 2 ){
        leftright = "LEFT.";
    } else if ( goldCol > 3 ) {
        leftright = "RIGHT.";
    } else if (goldCol == 2 || goldCol == 3){
        leftright = "MIDDLE.";
    }
    
    string fluffEnd = "\nHe says that last part real loud as he sways before vomiting on your shoes.\n";

    fluff.append(updown);
    fluff.append(leftright);
    fluff.append(fluffEnd);

    return fluff; 
} //end rainbowMessage()

void GoldMine::revealSelection(int row, int column){
    //TODO
    char found  = boxType.getElement(row, column);
    switch(found){

        case '-': if ( visited.getElement(row, column)){
                    cout << "You've already been here, dummy. Go home you're drunk.\n";
                  }
                  if ( !visited.getElement(row, column) ){              
                    cout << "You found nothing except a discarded beer bottle with a couple drops left... which you voraciously consume.\n";
                    cout << "Lose " << goldAmount.getElement(row, column) << " sobriety you depressing alcoholic.\n";
                    cout << "Current Sobriety: " << getGold() << ".\n";
                    this->gold -= goldAmount.getElement(row, column);
                    visited.setElement(row, column, true);
                  }
                  break;

        case 'R': cout << rainbowMessage();
                  visited.setElement(row, column, true);
                  break;
        
        case 'G': cout << "You WON! You found the Aqua Tequila and will live without hangovers for";
                  cout << " the rest of your life! Congratulations.\n";
                  cout << endl;
                  visited.setElement(row, column, true);
                  playAgain();
                  break;

        case 'C': cout << "You LOST! You found an old Chinese place that sells you dragon soup ";
                  cout << "(at a exorbiant price) which permanently causes you to be sad drunk!\n";
                  cout << "Never again will you be allowed at parties.\n";
                  cout << endl;
                  visited.setElement(row, column, true);
                  playAgain();
                  break;

        default: cout << "ERROR, you found something in our char array \n";
                 break;
    }
} //end revealSelection()

void GoldMine::printGoldMine(){
    //TODO
    cout << "\t0\t1\t2\t3\t4\t5\n";
    for( int i = 0; i < 6; i++){
        cout << i;
        for( int j = 0; j < 6; j++){
            cout << "\t";
            if( visited.getElement(i, j) == false){
                cout << "*";
            } else {
                cout << boxType.getElement(i,j);
            }
        }
        cout << endl; //new row
    }
} 

int GoldMine::getGold(){ return gold; }

void GoldMine::setGoldLocation(int row, int column){
    goldRow = row;
    goldCol = column;
}

void GoldMine::playAgain(){
    char input;
    do{
        cout << "Would you like to play again? [Y/N]: \n";
        cin >> input;
    } while(input != 'Y' && input != 'y' && input != 'N' && input != 'n');
    
    if(input == 'N' || input == 'n'){
        cout << "Have a nice day drink.\n";
        exit(0);
    }
    
    if( input == 'Y' || input == 'y'){
        resetGame();
    }
}
