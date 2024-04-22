//
//  MultiMap.cpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#include "MultiMap.hpp"
#include "MultiMapIterator.hpp"
#include <exception>
#include <iostream>


using namespace std;



// Complexity:  Θ(n)
MultiMap::MultiMap() {
    
    this->capacity = 4;
    this->head = -1;
    this->nrElements = 0;
    this->elements = new TElem[this->capacity];
    this->next = new int[this->capacity];
    for (int i = 0; i < this->capacity-1; i++) {
        this->next[i] = i + 1;
    }
    this->next[this->capacity-1] = -1;
    this->firstEmpty = 1;
}




// Complexities:
//      Worst case: O(n^2)
//      Best Case: O(1)
//      Average Case: Θ(1) amortisiert
void MultiMap::add(TKey c, TValue v) {
    
    if (this->firstEmpty == -1) { //array full -> resize
        
        int capDoubled = this->capacity * 2;
                
        TElem* newElements = new TElem[capDoubled];
        int* newNexts = new int[capDoubled];

        for (int i = 1; i <= this->capacity; i++) {
            newElements[i].first = this->elements[i].first;
            newElements[i].second = this->elements[i].second;
            newNexts[i] = this->next[i];

        }
        
        delete[] this->elements;
        delete[] this->next;
        
        this->elements = new TElem[capDoubled];
        this->next = new int[capDoubled];
        
        for (int i = this->capacity; i < this->capacity*2-1; i++) {
            newNexts[i] = i + 1;
        }
        
        newNexts[this->capacity*2-1] = -1;
        
        for (int i = 1; i < this->capacity*2; i++) {
            this->elements[i].first = newElements[i].first;
            this->elements[i].second = newElements[i].second;
            this->next[i] = newNexts[i];
            
        }
        
        this->firstEmpty = this->capacity;
        this->capacity *= 2;
        
    }
        
    
    TElem elem = std::make_pair(c, v);
    int newPosition = this->firstEmpty;
    
    this->elements[newPosition] = elem;
    this->firstEmpty = this->next[this->firstEmpty];
    this->next[newPosition] = this->head;
    this->head = newPosition;
    this->nrElements++;
}



// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: O(n)
bool MultiMap::remove(TKey c, TValue v) {
    
    TElem elem = std::make_pair(c, v);
    int current = this->head;
    int previousNode = -1;
    
    while(current != -1 and this->elements[current] != elem) {
        previousNode = current;
        current = this->next[current];
    }
    
    if (current != -1) {
        if (current == this->head) {
            this->head = this->next[this->head];
        } else {
            this->next[previousNode] = this->next[current];
        }
        
        this->next[current] = this->firstEmpty;
        this->firstEmpty = current;
        this->nrElements--;
        return true;
    }
    return  false;
}




// Complexities:
//      Worst case: O(n)
//      Best Case: O(1)
//      Average Case: O(n)
vector<TValue> MultiMap::search(TKey c) const {
        
    vector<TValue> result;
    int current = this->head;
    
    while (current != -1) {
        if (this->elements[current].first == c) {
            result.push_back(this->elements[current].second);
        }
        current = this->next[current];
    }
    return result;
}




// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: O(1)
int MultiMap::size() const {
    return this->nrElements;
}




// Complexities:
//      Worst case: O(1)
//      Best Case: O(1)
//      Average Case: O(1)
bool MultiMap::isEmpty() const {
    if (this->nrElements == 0) {
        return true;
    }
    return false;
}



// Complexity : O(n)
int MultiMap::getNumberOfValues(TKey key) {
    
    int current = this->head;
    int nrValues = 0;
    
    while (current != -1) {
        if (this->elements[current].first == key) {
            nrValues++;
        }
        current = this->next[current];
    }
    return nrValues;
}



// Complexity : O(n)
unsigned long MultiMap::getNumberOfValuesWithSearch(TKey key) {
    
    return this->search(key).size();
}


//void MultiMap::toString() {
//    int current = this->head;
//    cout << "Head found at position: " << current << endl;
//
//    while (current != -1) {
//        cout << "(" << this->elements[current].first << ", " << this->elements[current].second << ")";
//        current = this->next[current];
//    }
//
//    cout << endl;
//}




MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
}




MultiMap::~MultiMap() {
    delete[] this->elements;
    delete[] this->next;
}

