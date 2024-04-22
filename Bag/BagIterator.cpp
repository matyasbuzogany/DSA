#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
    this->index = 0;
    this->frequency = 0;
}

void BagIterator::first() {
	this->index = 0;
	this->frequency = this->bag.elements[this->index].second;
}


void BagIterator::next() {
    int currfreq = 0;
    if((this->index < this->bag.nrElements) && (currfreq == this->frequency)) {
        this->index++;
    } else {
        throw exception();
    }
}


bool BagIterator::valid() const {
	if (this->index < this->bag.nrElements) {
	    cout << "Valid" << endl;
	    return true;
	}
	return false;
}


TElem BagIterator::getCurrent() const
{
    if (this->index < this->bag.nrElements) {
        cout << "Current element: " << bag.elements[this->index].first << endl;
        return this->bag.elements[this->index].first;

    } else {
        throw exception();
    }
}
