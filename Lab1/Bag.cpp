//
//  Bag.cpp
//  Lab1
//
//  Created by Matyas Buzogany on 23.02.2021.
//

#include "Bag.hpp"
#include "BagIterator.hpp"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
    this->nrElements = 0;
    this->nrPairs = 0;
    this->capacity = 1;
    this->elements = new std::pair<TElem, int>[this->capacity];
}



// Complexities:
//      Worst case: O(n^3)
//      Best Case: Θ(1) amortisiert
//      Average Case: Θ(n) amortisiert
void Bag::add(TElem elem) {
    bool found = false;
    
    // Complexity: Θ(n)
    for (int i = 0; i < this->nrPairs; i++) {
        if (this->elements[i].first == elem) {
            this->elements[i].second++;
            this->nrElements++;
            found = true;
        }
    }
    
    if (!found) {
        if (this->nrPairs == this->capacity) {
            this->capacity *= 2;
            std::pair<TElem, int>* newElements = new std::pair<TElem, int> [this->capacity];

            // Complexity: Θ(n)
            for (int i = 0; i < this->capacity; i++) {
                newElements[i].first = this->elements[i].first;
                newElements[i].second = this->elements[i].second;
            }
            
            delete[] this->elements;
            this->elements = new std::pair<TElem, int>[this->capacity];
            
            // Complexity: Θ(n)
            for (int i = 0; i < this->capacity; i++) {
                this->elements[i].first = newElements[i].first;
                this->elements[i].second = newElements[i].second;
            }
            
            delete[] newElements;
        }
        
        // Complexity: O(1)
        std::pair<TElem, int> newpair = std::make_pair(elem, 1);
        this->elements[this->nrPairs] = newpair;
        this->nrElements++;
        this->nrPairs++;
    }
}



// Complexities:
//      Worst Case: O(n)
//      Best Case: O(1) -> first element, nr. appearances > 1
//      Average Case: Θ(n)
bool Bag::remove(TElem elem) {
    if (this->nrElements == 0) {
        return false;
    }
    
    for (int i = 0; i < this->nrPairs; i++){
        if (this->elements[i].first == elem) {
            this->elements[i].second--;
            this->nrElements--;

            if (this->elements[i].second == 0) {
                this->nrPairs--;
                for (int j = i; j < this->nrPairs; j++) {
                    this->elements[j] = this->elements[j+1];
                }
                return true;
            }
            return true;
        }
    }
    return false;
}



// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: Θ(n)
bool Bag::search(TElem elem) const {
    if (this->nrElements == 0) {
        return false;
    }
    
    for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i].first == elem) {
            return true;
        }
    }
    return false;
}



// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: Θ(n)
int Bag::nrOccurrences(TElem elem) const {
    if (this->nrElements == 0) {
        return false;
    }
    for (int i = 0; i < this->nrElements; i++) {
        if (this->elements[i].first == elem) {
            return this->elements[i].second;
        }
    }
    return 0;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
int Bag::size() const {
    return this->nrElements;
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
bool Bag::isEmpty() const {
    if (this->nrElements >= 1) {
        return false;
    }
    return true;
}




void Bag::toString() {
    cout << "Elements :" << endl;
    for (int i = 0; i < this->nrPairs - 1; i++) {
        cout <<"(" << this->elements[i].first << ", " << this->elements[i].second <<"), ";
    }
    cout << "("<<this->elements[this->nrPairs-1].first << ", " << this->elements[this->nrPairs-1].second << ")" << endl;
}



std::pair<TElem, int>* Bag::getElements() {
    return this->elements;
}


// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}



// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: Θ(1)
Bag::~Bag() {
    delete[] this->elements;
}

