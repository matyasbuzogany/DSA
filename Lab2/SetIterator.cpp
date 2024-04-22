//
//  SetIterator.cpp
//  Lab2
//
//  Created by Matyas Buzogany on 14.03.2021.
//

#include <iostream>
#include "SetIterator.hpp"
#include "Set.hpp"

using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
    this->head = m.head;
    this->currentNode = m.head;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
void SetIterator::first() {
    this->currentNode = this->head;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
void SetIterator::next() {
    if (this->valid()) {
        this->currentNode = this->currentNode->next;
    } else {
        throw exception();
    }
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
TElem SetIterator::getCurrent()
{
    if (this->valid()) {
        return this->currentNode->value;
    } else {
        throw exception();
    }
    return NULL_TELEM;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
bool SetIterator::valid() const {
    if (this->currentNode != NULL) {
        return true;
    }
    return false;
}
