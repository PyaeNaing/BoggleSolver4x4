#include "BoggleSolver.h"
#include "Dictionary.h"
#include <string>
#include <iomanip>
#include <fstream>

BoggleSolver::BoggleSolver(Dictionary d)
{
    //Post : .txt file is created with the solution.

    dic = &d;
    ofstream out;
    out.open("Board.txt");

    cout << "Enter Board" << endl;
    out << "Enter Board" << endl;

    cout << "-----------" << endl;
    out << "-----------" << endl;


    for (int i = 0; i < 4; i++)
    {
        cout << "Row " << i << ": ";
        out << "Row " << i << ": ";

        for(int j = 0; j < 4; j++)
        {
            cin >> board [i][j];
            out << board [i][j] << " ";
        }
        out << endl;
    }

    cout << endl << "Show Board (y/n)?: ";
    out << endl << "Show Board (y/n)?: ";
    char ans;
    cin >> ans;
    out << ans << endl;
    if (ans == 'y')
        show = true;
    else
        show = false;

    boardsearch(out);

    if (!show)
    {
        print(out);
    }
    cout << Copy.wordCount() << " words." << endl;
    out << Copy.wordCount() << " words." << endl;


    out.close();
    //ctor
    /**/
}

void BoggleSolver::boardsearch(ofstream & out)
{
    // Post searched all the possbile word in 4x4
    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 4; c++)
        {
            string s = "";
            setfalse();
            searchforword(r, c, s, 0, out);
        }
}

void BoggleSolver::searchforword(int r, int c, string s, int step, ofstream & out)
{
    //pre : the row and col are in bound, have not travel to here yet
    //post : if show board, print it to .txt file
    if ((r < 0 || r > 3) || (c < 0 || c > 3))
    {
        return;
    }
    // Traveled Here?
    if(tra[r][c])
        return;

    s += board[r][c];

    if (!dic->isPrefix(s))
        return;

    tra[r][c] = true;
    int temp = travled[r][c];

    travled[r][c] = step + 1;

    if(dic->isWord(s))
    {
        if (s.length() > 2)
        {
            if(!Copy.isWord(s))
            {
                Copy.addWord(s);
                if (show)
                    printBoard(travled, s, out);
            }
        }
    }

    searchforword(r-1, c, s, step + 1, out); //1 o clock
    searchforword(r-1, c+1, s, step + 1, out); // 3
    searchforword(r-1, c-1, s, step + 1, out); // 5
    searchforword(r+1, c-1, s, step + 1, out);
    searchforword(r+1, c+1, s, step + 1, out);
    searchforword(r+1, c, s, step + 1, out); // 6
    searchforword(r, c-1, s, step + 1, out); // 8
    searchforword(r, c+1, s, step + 1, out); //9

    travled[r][c] = temp;
    tra[r][c] = false;

};

void BoggleSolver::setfalse()
{

    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 4; c++)
            travled[r][c] = 0;
}
void BoggleSolver::print(ofstream & out)
{
    Copy.PrintAll();
    printf(Copy.root, out);

}

void BoggleSolver::printf(Node * cur, ofstream & out)
{
    // pre : current node is not null
    // Post : the word is printed into file
    if(cur == nullptr)
        return;

    if(cur -> Word)
    {

        cout << cur->ch << endl;
        out << cur -> ch << endl;
    }

    for(int i = 0; i < 26; i++)
    {
        if(cur -> alpha[i] != nullptr)
        {
            printf(cur->alpha[i], out);
        }
    }
}


void BoggleSolver::printBoard(int step[4][4], string s, ofstream & out)
{
    // Post : board is  printed
    cout << "Word: " << s << endl;
    out << "Word: " << s << endl;
    cout << "Numbers of Word: " << countP << endl;
    out << "Numbers of Word: " << countP << endl;
    for(int r = 0; r < 4; r++)
    {
        for(int c = 0; c < 4; c++)
        {
            if(travled[r][c] != 0)
            {
                string temp = "";
                temp = temp + "'" + board[r][c] + "'";
                cout << setw(3) << temp << "  ";
                out << setw(3) << temp << "  ";

            }
            else
            {
                cout << setw(2) << board[r][c] << "   ";
                out << setw(2) << board[r][c] << "   ";
            }
        }
        for(int c = 0; c < 4; c++)
        {
            cout << setw(3) <<travled[r][c] << setw(3);
            out << setw(3) <<travled[r][c] << setw(3);

        }
        cout << endl;
        out << endl;

    }
    cout << endl;
    out << endl;
    countP++;
}

