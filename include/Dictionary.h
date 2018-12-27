#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Node
{
    Node* alpha [26];
    Node()
    {
        for(int i = 0; i < 26; i++)
            alpha [i] = nullptr;
    }
    bool Word = false;
    string ch = "";
};

class Dictionary
{
public:
    Dictionary();                   //done
    Dictionary(string file);        //done
    void addWord(string word);      //done
    bool isWord(string word);       //done
    bool isPrefix(string word);     //done
    void PrintWords(string prefix); //done
    int wordCount();
    void PrintAll();
    Node * root;



private:
    void print(Node* node);
    int numWords;



    // Your private helper methods go here*/

};

#endif // DICTIONARY_H
