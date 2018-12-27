#ifndef BOGGLESOLVER_H
#define BOGGLESOLVER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Dictionary.h"
#include <stack>


class BoggleSolver
{
public:

    BoggleSolver(Dictionary);


private:
    char board[4][4]= {};
    int travled [4][4] = {{0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    bool tra [4][4] = {{false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    void setfalse();
    void print(ofstream &);
    void printf(Node*,ofstream&);
    void printBoard(int[4][4], string, ofstream&);
    void boardsearch(ofstream&);
    void searchforword(int, int, string, int, ofstream&);
    bool show;
    Dictionary * dic;
    Dictionary Copy;
    int countP = 1;

};

#endif // BOGGLESOLVER_H
