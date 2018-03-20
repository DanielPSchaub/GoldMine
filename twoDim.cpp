//Daniel Schaub, Spring 2018
#ifndef TWODIMCPP
#define TWODIMCPP

#include "twoDim.h"

template<class LE> twoDim<LE>::twoDim(){

}
/*THIS SHOULD BE A 2nd METHOD OF CREATING A NEW BOARD, BUT IS LESS VERSATILE
template<> twoDim<bool>::twoDim(){
    for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            array[i][j] = false;   
        }
}
template<> twoDim<char>::twoDim(){
     for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            array[i][j] = '_';   
        } 
}
template<> twoDim<int>::twoDim(){
     for(int i = 0; i < 6; i++) //hard coded array size
        for(int j = 0; j < 6; j++){
            array[i][j] = rand() % 1000 ;   
        }
}
*/
template<class LE> LE twoDim<LE>::getElement( int row, int col){
    return array[row][col];
}
template<class LE> void twoDim<LE>::setElement( int row, int col, LE element){
    array[row][col] = element;
}

#endif
