//
//  MultiMapIterator.cpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#include "MultiMapIterator.hpp"
#include "MultiMap.hpp"


// Complexity: O(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    this->head = col.head;
    this->currentIndex = col.head;
}



// Complexity: O(1)
TElem MultiMapIterator::getCurrent() const{
    if (this->valid()) {
        return this->col.elements[currentIndex];
    } else {
        throw exception();
    }
    
}



// Complexity: O(1)
bool MultiMapIterator::valid() const {
    if (this->currentIndex != -1)
        return true;
    return false;
}



// Complexity: O(1)
void MultiMapIterator::next() {
    if (this->valid()) {
        this->currentIndex = col.next[currentIndex];
    } else {
        throw exception();
    }
    
}



// Complexity: O(1)
void MultiMapIterator::first() {
    this->currentIndex = this->head;
}

