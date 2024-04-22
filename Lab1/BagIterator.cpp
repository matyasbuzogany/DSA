//
//  BagIterator.cpp
//  Lab1
//
//  Created by Matyas Buzogany on 23.02.2021.
//

#include <exception>
#include "BagIterator.hpp"
#include "Bag.hpp"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c){
    this->index = 0;
    this->frequency = this->bag.elements[this->index].second;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1) 
void BagIterator::first() {
    this->index = 0;
    this->frequency = this->bag.elements[this->index].second;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
void BagIterator::next() {
    if (this->valid()) {
        if (this->frequency < 2) {
            this->index++;
            this->frequency = this->bag.elements[this->index].second;
        } else {
            this->frequency--;
        }
    } else {
        throw exception();
    }
    
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
bool BagIterator::valid() const {
    if(this->index < this->bag.nrPairs) {
        return true;
    }
    return false;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
TElem BagIterator::getCurrent() const
{
    if (this->valid()) {
        return this->bag.elements[this->index].first;
    } else {
        throw exception();
    }
    return NULL_TELEM
}
