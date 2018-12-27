#include <iostream>
#include "Dictionary.h"
#include "BoggleSolver.h"
#include <string>

using namespace std;

int main()
{
//    Dictionary a;
    Dictionary dict("Dictionary.txt");
    cout << dict.wordCount() << " words loaded." << endl << endl;
    cout << "the board size is 4 x 4 break the each letter with space or with return key "<< endl;
    BoggleSolver b(dict);
    return 0;
}
