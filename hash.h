//
// Created by Vinh Van Tran on 4/25/16.
//

#ifndef TEST_HASH_H
#define TEST_HASH_H


#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class hashE{
    private:

        static const int tableSize =1373;

        struct Node{
            string data;
            Node* next;
        };
        Node* HashTable[tableSize];

public:
        hashE();
        int Hash(const string Item);

        //unsigned int operator()(const string& item) const;

        int numberOfItems(int index);
        void print();
        void addNode(string newData);
        bool misSpell(string Item);

};



#endif //TEST_HASH_H
