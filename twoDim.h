//Daniel Schaub, Spring 2018
#ifndef TWODIMH
#define TWODIMH

template <class LE>
class twoDim{
 public: 
    twoDim();
    LE getElement( int row, int col);
    void setElement( int row, int col, LE element);
 private:
    LE array[6][6];
};
#include "twoDim.cpp"
#endif
