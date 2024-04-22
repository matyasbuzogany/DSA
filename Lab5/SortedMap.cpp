//
//  SortedMap.cpp
//  Lab5
//
//  Created by Matyas Buzogany on 28.04.2021.
//

#include "SortedMap.hpp"
#include "SortedMapIterator.hpp"
#include <exception>
#include <stdio.h>
#include <iostream>

using namespace std;

SortedMap::SortedMap(Relation r) {
    this->m = 7907;
    this->nrElements = 0;
    this->elements = new TElem[this->m];
    this->nexts = new int[this->m];
    for (int i = 0; i < this->m; i++) {
        this->nexts[i] = -1;
        this->elements[i].first = -1;
        this->elements[i].second = -1;
    }
    this->firstFree = 0;
    this->relation = r;
}




bool isPrime(int value) {
    for (int i = 2; i < value; i++) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}




int closestPrimeNumber(int value) {
    value = (value * 2) + 1;
    while (isPrime(value) == false) {
        value+=2;
    }
    return value;
}




TValue SortedMap::add(TKey k, TValue v) {
    
    int position = this->hashFunction(k);
    int returnValue = NULL_TVALUE;
    int current = 0;
    bool keyFound = false;
    
    
    //If the key already exists, modify the value of it and return the old value
    while (current <= this->m and keyFound == false) {
        
        if (this->elements[current].first == k) {
            keyFound = true;
//            cout << "Key found! " << this->elements[current].first <<", Value: " << this->elements[current].second << endl;
            returnValue = this->elements[current].second;
            this->elements[current].second = v;
//            cout << "New value: " << v << endl;
//            cout << "Return value: " << returnValue << endl;
            return returnValue;
        }
        current++;
    }


    //If the key doesnt exist, we create a new pair and return NULL_VALUE
    if (this->elements[position].first == -1) {
        this->elements[position].first = k;
        this->elements[position].second = v;
        this->nexts[position] = -1;
        this->nrElements++;
        return returnValue;
        
    } else {
//        int oldValue = this->elements[position].second;
        int current = position;
        
//        this->elements[position].second = v;
        
        while (this->nexts[current] != -1) {
            current = this->nexts[current];
        }
        
        if (this->firstFree == this->m) {
            //TODO
            int newSize = closestPrimeNumber(this->m);
            
            cout << "Cap doble required!" << endl;
            
        } else {
            this->elements[this->firstFree].first = k;
            this->elements[this->firstFree].second = v;
            this->nexts[this->firstFree] = -1;
            this->nexts[current] = this->firstFree;
            this->nrElements++;
            
            this->firstFree += 1;
            while (this->firstFree < this->m and this->elements[this->firstFree].first != -1) {
                this->firstFree += 1;
            }
            return returnValue;
        }
        
    }
    
    return returnValue;
}




TValue SortedMap::search(TKey k) {
    int index = this->hashFunction(k);
    
    while (index != -1 and this->elements[index].first != k) {
        index = this->nexts[index];
    }
    
    if (index == -1) {
        return NULL_TVALUE;

    }
    return this->elements[index].second;
}




TValue SortedMap::remove(TKey k) {
    int i = this->hashFunction(k);
    int value = this->elements[i].second;
    int j = -1;
    int l = 0;
    
    while (l < this->m and j == -1) {
        if (this->nexts[l] == i) {
            j = l;
        }
        j++;
    }
    
    while (i != -1 and this->elements[i].first != k) {
        j = i;
        i = this->nexts[i];
    }
    
    if (i == -1) {
        return NULL_TVALUE;
    } else {
        bool over = false;
        
        while (over == false) {
            int p = this->nexts[i];
            int pp = i;
            
            while (p != -1 and this->hashFunction(this->elements[p].first) != i) {
                pp = p;
                p = this->nexts[p];
            }
            
            if (p == -1) {
                over = true;
            } else {
                this->elements[i].first = this->elements[p].first;
                this->elements[i].second = this->elements[p].second;
                j = pp;
                i = p;
            }
        }

        if (j != -1) {
            this->nexts[j] = this->nexts[i];
        }
        
        this->elements[i].first = -1;
        this->elements[i].second = -1;
        this->nexts[i] = -1;
        
        if (this->firstFree > i) {
            this->firstFree = i;
        }
        this->nrElements--;
        return value;
    }
    
    return NULL_TVALUE;
}




int SortedMap::size() const {
    return this->nrElements;
}




bool SortedMap::isEmpty() const {
    if (this->nrElements != 0) {
        return false;
    }
    return true;
}




void SortedMap::toString() {
    for (int i = 0; i < this->m; i++) {
        cout << "(" <<this->elements[i].first << ", " <<this->elements[i].second << ")" <<" , next: " <<this->nexts[i] <<endl;
    }
}




SortedMapIterator SortedMap::iterator() const {
    return SortedMapIterator(*this);
}




SortedMap::~SortedMap() {
    //TODO - Implementation
}
