// intlist.cpp
// Implements class IntList
// Jesus Velarde Arvayo; April 22, 2021

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    Node* sourceNode = source.first;

    Node* node;
    if(sourceNode){
        node = new Node;
    }

    while(sourceNode){
        node->info = sourceNode->info;
        node->next = nullptr;

        if(source.first == sourceNode){
            first = node;
        }
        if(sourceNode->next){
            node->next = new Node;
        }
        sourceNode = sourceNode->next;
        node = node->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* node;
    while(first){
        node = first->next;
        delete first;
        first = node;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum(0);
    Node *node = first;
    while(node){
        sum += node->info;
        node = node->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* node = first;
    while(node){
        if(node->info == value)
            return true;
        node = node->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;
    if(!first)
        return 0;
    Node *node = first;
    max = first->info;
    while(node){
        if(node->info > max)
            max = node->info;
        node = node->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {

    double sum(0);
    int n(0);

    Node *node = first;
    while(node){
        n++;
        sum += node->info;
        node = node->next;
    }
    if(n == 0)
        return 0.0;

    return sum/static_cast<double>(n); 
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if(first == 0){
        first = new Node;
        first->info = value;
        first->next = 0;
    }else{
        Node* node = new Node;
        node->info = value;
        node->next = first;
        first = node;
    }
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    this->~IntList();

    Node* sourceNode = source.first;

    Node* node;
    if(sourceNode){
        node = new Node;
    }

    while(sourceNode){
        node->info = sourceNode->info;
        node->next = nullptr;

        if(source.first == sourceNode){
            first = node;
        }
        if(sourceNode->next){
            node->next = new Node;
        }
        sourceNode = sourceNode->next;
        node = node->next;
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
