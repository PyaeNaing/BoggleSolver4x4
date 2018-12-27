#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Dictionary::Dictionary()
{
    //Make the Root Node Null
    root = new Node;
    numWords = 0;
    //ctor
}


Dictionary::Dictionary(string file)
{
    //Pre : File is valid to load
    //Post : all the word from the file is loaded.
    root = new Node;
    numWords = 0;
    ifstream infile;

    infile.open(file.c_str());
    if(!infile)
    {
        cout << "Error opening a file" << endl;
    }
    else
    {

        while(!infile.eof())
        {
            string a;
            infile >> a;
            addWord(a);
        }
    }
    infile.close();
}

void Dictionary::addWord(string word)
{
    //Pre : root exist;
    //Post : word has been added to the dictionary
    //       Flag is true in the location of word.
    Node* current = root;
    for(int i = 0; i < word.length(); i++)
    {
        int j = (int) word[i] - (int) 'a';
        if(current->alpha[j] == nullptr)
        {
            Node * p = new Node;
            p -> ch += current->ch + word[i];
            current->alpha[j] = p;
        }
        current = current -> alpha[j];
    }
    if(current->Word)
        return;
    current->Word = true;
    numWords++;
}

bool Dictionary::isWord(string word)
{
    //Post : return true if word, false if not
    Node* current = root;
    for(int i = 0; i < word.length(); i++)
    {
        int j = (int) word[i] - (int) 'a';
        if(current -> alpha[j] == nullptr)
            return false;
        current = current -> alpha[j];

    }
    return current ->Word;
}

bool Dictionary::isPrefix(string word)
{
    //Post : return true if prefix, false if not
    Node* current = root;
    for(int i = 0; i < word.length(); i++)
    {
        int j = (int) word[i] - (int) 'a';
        if(current -> alpha[j] == nullptr)
            return false;
        current = current -> alpha[j];
    }
    return true;
}

void Dictionary::PrintWords(string prefix)
{
    //Pre: have a prefix
    //Post : print out the word to console.
    Node * current = root;
    for(int i = 0; i < prefix.length(); i++)
    {
        int j = (int) prefix[i] - (int) 'a';
        if(current -> alpha[j] == nullptr)
            return;
        current = current -> alpha[j];
    }
    print(current);
    cout << endl;
}

void Dictionary::print(Node * cur)
{
    // Recursive function called and the purpose is for printing. A helper function.
    // Pre : current node isnt null;
    // Post : print out.
    if(cur == nullptr)
        return;

    if(cur -> Word)
        cout << cur->ch << endl;

    for(int i = 0; i < 26; i++)
    {
        if(cur -> alpha[i] != nullptr)
        {
            print(cur->alpha[i]);
        }
    }
}

void Dictionary::PrintAll()
{
    print(root);
}

int Dictionary::wordCount()
{
    return numWords;
}
