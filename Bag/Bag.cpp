#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->nrElements = 0;
	this->capacity = 1;
	this->nrPairs = 0;
	this->elements = new std::pair<TElem, unsigned int>[this->capacity];
}



//Complexity : O(n)
void Bag::add(TElem elem) {

    if (this->nrPairs == this->capacity) {
        cout << "Capacity " << this->capacity << " doubled: ";
        this->capacity = this->capacity * 2;
        cout << this->capacity << endl;
        auto* newElems = new std::pair<TElem, unsigned int> [this->capacity];

        for (int i = 0; i < this->nrElements; i++) {
            newElems[i].first = this->elements[i].first;
            newElems[i].second = this->elements[i].second;
        }

        for (int i = 0; i < this->nrElements; i++) {
            this->elements[i].first = newElems[i].first;
            this->elements[i].second = newElems[i].second;
        }
    }

    bool found = false;

    for (int i = 0; i < this->nrPairs; i++) {
        if (this->elements[i].first == elem) {
            this->elements[i].second++;
            this->nrElements++;
            found = true;
            cout << "Incremented number of occurence for Element: " << elem << " !" << endl;
        }
    }

    if (!found) {
        std::pair<TElem , unsigned int> newPair = std::make_pair(elem, 1);
        this->elements[this->nrPairs] = newPair;
        this->nrElements++;
        this->nrPairs++;
        cout << "New Element: " << elem << " has been added!" << endl;
    }

}



// Complexity : O(n)
bool Bag::remove(TElem elem) {

	if (this->nrElements == 0) {
	    cout << "Remove function returned false, cuz nrelems == 0" << endl;
	    return false;
	}

    for (int i = 0; i < this->nrPairs; i++)
    {
        if (this->elements[i].first == elem) {
            this->elements[i].second--;
            this->nrElements--;

            if (this->elements[i].second == 0) {
                this->nrPairs--;
                for (int j = i; j < this->nrPairs; j++) {
                    this->elements[j] = this->elements[j+1];
                }
                cout << "Element "<< elem << " removed!" << endl;
                return true;
            }

            cout << "Element "<< elem << " removed!" << endl;
            return true;
        }
    }
    cout << "Element " << elem << " not found, therefore not removed!" << endl;
    return false;
}



// Complexity : O(n)
bool Bag::search(TElem elem) const {

    if (this->nrElements == 0) {
        return false;
    }

	for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i].first == elem) {
            cout << "Element: " << elem << " found!" << endl;
            return true;
        }
	}
    cout << "Element " << elem << " not found!" << endl;
    return false;
}



// Complexity : O(n)
int Bag::nrOccurrences(TElem elem) const {
    if (this->nrElements == 0) {
        return 0;
    }
    for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i].first == elem) {
            cout << "Number of occurences for " << elem << ": " << this->elements[i].second << endl;
            return this->elements[i].second;
        }
    }
	return 0;
}



// Complexity : O(1)
int Bag::size() const {
	cout << "Number of Elements in the bag: " << this->nrElements << "  ;  Number of Pairs in the Bag: " << this->nrPairs << endl;
	return this->nrElements;
}



//Complexity : O(1)
bool Bag::isEmpty() const {

    if (this->nrElements < 1) {
        cout << "Bag is Empty!" << endl;
        return true;
    }
    cout << "Bag is NOT Empty!" << endl;
	return false;
}



void Bag::printAll() {
    cout << "Elements :" << endl;
    for (int i = 0; i < this->nrPairs; i++) {
        cout <<"(" << this->elements[i].first << ", " << this->elements[i].second <<"), ";
    }
}



BagIterator Bag::iterator() const {
	return BagIterator(*this);
}



Bag::~Bag() {
    delete[] this->elements;
}

