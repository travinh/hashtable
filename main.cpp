#include <iostream>
#include <string>
#include <fstream>


#include "hash.h"

using namespace std;

ifstream& getWord(ifstream& fin, string& w);

int main()
{
    hashE newHash;

    //create inputData to input data from file
    ifstream inputData;

    inputData.open("dict.dat");

    if (inputData.fail())
        cout << "File dictionary not found" << endl;

    string word;
    inputData >>word;
    while(!inputData.eof())
    {

        newHash.addNode(word);
        inputData>>word;

    }
    //newHash.print();

    inputData.close();

    ifstream inputWord;
    inputWord.open("data.txt");

    if(inputWord.fail())
        cout << "Input text file is not found"<<endl;

    string testWord;
    cout << "Here is your miss spelled words: "<<endl;
    cout <<" -----------------------------------------------"<<endl;
    while(getWord(inputWord, testWord))
    {
        //cout << testWord <<endl;
        if(newHash.misSpell(testWord))
            cout <<testWord <<endl;
    }

    inputWord.close();




//    cout << "weodsaodoasd"<<endl;
//    newHash.addNode("strange");
//    newHash.addNode("hate");
//
//    newHash.print();

    return 0;




}
ifstream& getWord(ifstream &fin, string &w) {
    char c;

    w = ""; // clear the string of characters

    while (fin.get(c) && !isalpha(c)); // do nothing. just ignore c

    // return on end-of-file
    if (fin.eof())
        return fin;

    // record first letter of the word
    w += tolower(c);

    // collect letters and digits
    while (fin.get(c) && (isalpha(c) || isdigit(c)))
        w += tolower(c);

    return fin;
}