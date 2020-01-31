//
// Created by Vinh Van Tran on 4/25/16.
//

#include <iostream>
#include <string>
#include <fstream>

#include "hash.h"

using namespace std;

hashE::hashE() {
    for (int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new Node;
        HashTable[i]->data ="\0";
        HashTable[i]->next = nullptr;
    }

}

int hashE::Hash(string item) {
    unsigned int prime = 1373;

    int n = 0, i;

    for (i = 0; i < item.length(); i++)
    n = n*8 + item[i];

  return n > 0 ? (n % prime) : (-n % prime);

}




void hashE::addNode(string newData) {
    int index= Hash(newData);
    //cout <<"index: "<<index;
    if (HashTable[index]->data == "\0")
    {
        HashTable[index]->data = newData;
//        cout <<"\nHashindex:" <<HashTable[index]->data <<endl;
    }
    else
    {
        Node *Ptr = HashTable[index];
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = nullptr;

        while (Ptr->next != nullptr)
        {
            Ptr= Ptr->next;
        }

        Ptr->next= newNode;
    }

}

void hashE::print() {
    int number;
    int total = 0;

    for (int i = 0; i < tableSize; i++) {
        number = numberOfItems(i);
        cout << " ----------------------------" << endl;
        cout << "Index: " << i << endl;
        cout << "Number of items:" << number << endl;
        //cout << HashTable[i]->data<<endl;
        Node* Ptr = HashTable[i];
        while (Ptr->next!=nullptr)
        {
            Ptr= Ptr->next;
            //cout << Ptr->data<<endl;
        }
        total+=number;

        //cout <<"Total is: "<<total<<endl;
    }
        cout << "Total is: " << total << endl;


}


    int hashE::numberOfItems(int index) {

        int count = 0;

        if (HashTable[index]->data == "\0") {
            return count;
        }

        else {
            count++;
            Node *Ptr = HashTable[index];
            while (Ptr->next != nullptr) {
                count++;
                Ptr = Ptr->next;
            }

        }

        return count;
    }

//unsigned int hashE::operator()(const string &item) const
//{
//
//    unsigned int prime = 1373;
//
//    int n = 0, i;
//
//    for (i = 0; i < item.length(); i++)
//    n = n*8 + item[i];
//
//  return n > 0 ? (n % prime) : (-n % prime);
//}
//
bool hashE::misSpell(string Item) {
    bool answer = true;
    int index = Hash(Item);

    Node* Ptr = HashTable[index];
//    cout <<"Item:" << Item << " -Index : "<<index <<endl;
//    cout <<" -----------------" <<endl;

    //cout <<HashTable[index]->data<<endl;
    while(Ptr->next != nullptr)
    {
        //cout <<Ptr->data<<endl;
        if (Ptr->data == Item)
        {
            answer =false;
            break;
        }
        Ptr= Ptr->next;
    }
    if (Ptr->data==Item)
        answer = false;


   // cout <<"answer = " <<answer <<endl;

    return answer;
}
