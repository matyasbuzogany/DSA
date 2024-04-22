//
//  Set.cpp
//  Lab2
//
//  Created by Matyas Buzogany on 14.03.2021.
//

#include <iostream>

#include "Set.hpp"
#include "SetIterator.hpp"

using namespace std;


Set::Set() {
    this->head = NULL;
    this->nrElements = 0;
}



// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: Θ(n)
bool Set::add(TElem elem) {
    
    if (this->head != NULL) {
        
        if (!this->search(elem)) {
            
            Node* nodeToAdd = new Node;
            nodeToAdd->next = NULL;
            nodeToAdd->value = elem;

            Node* currentNode = new Node;
            
            currentNode = this->head;
            
            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            }
            
            currentNode->next = nodeToAdd;
            this->nrElements++;
            return true;
            
        } else {
            return false;
        }
    }
    Node* nodeToAdd = new Node;
    nodeToAdd->next = NULL;
    nodeToAdd->value = elem;
    this->head = nodeToAdd;
    this->nrElements++;
    return true;
}




// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: Θ(n)
bool Set::remove(TElem elem) {
    
    if (this->nrElements == 0) {
        return false;
    }
    
    Node* nodeToDelete = NULL;
    Node* temp = this->head;
    Node* currentNode = this->head;
    
    while(currentNode != NULL && currentNode->value != elem) {
        temp = currentNode;
        currentNode = currentNode->next;
    }
    
    if (currentNode == NULL) {
        delete nodeToDelete;
        return false;
        
    } else {
        nodeToDelete = currentNode;
        currentNode = currentNode->next;
        temp->next = currentNode;
        
        if (nodeToDelete == this->head) {
            this->head = this->head->next;
            temp = NULL;
        }
        
        delete nodeToDelete;
        this->nrElements--;
        return true;
    }
}



// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: Θ(n)
bool Set::search(TElem elem) const {
    if (this->nrElements == 0) {
        return false;
    }
    
    Node* currentNode = this->head;
    
    while(currentNode != NULL) {
        if (currentNode->value == elem) {
            return true;
        }
        
        currentNode = currentNode->next;
    }
    
    return false;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
int Set::size() const {
    return this->nrElements;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
bool Set::isEmpty() const {
    if (this->nrElements < 1) {
        return true;
    }
    return false;
}




void Set::toString() {
    Node* curr = this->head;
    curr = this->head;
    while (curr != NULL) {
        cout << curr->value << ", ";
        curr = curr->next;
    }
    cout << endl;
}


TElem* Set::function(int lowerbound, int upperbound) {

    TElem newSet [100];
    int index = 0;

    Node* currentNode = this->head;

    while(currentNode != NULL) {
        if (currentNode->value <= upperbound && currentNode->value >= lowerbound) {
            newSet[index] = currentNode->value;
            index++;
        }
    }

    delete currentNode;

    return newSet;

}




Set::~Set() {
    
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
SetIterator Set::iterator() const {
    return SetIterator(*this);
}
