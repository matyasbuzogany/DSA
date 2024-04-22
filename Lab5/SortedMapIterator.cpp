//
//  SortedMapIterator.cpp
//  Lab5
//
//  Created by Matyas Buzogany on 28.04.2021.
//

#include "SortedMapIterator.hpp"
#include "SortedMap.hpp"
#include <exception>
#include <iostream>

using namespace std;


SortedMapIterator::SortedMapIterator(const SortedMap& m) : map(m){
    this->elementsSorted = new TElem[m.size()];
    int curr = 0;
    
    for (int i = 0; i < m.m; i++) {
        if (m.elements[i].first != -1) {
            this->elementsSorted[curr] = m.elements[i];
            curr++;
        }
    }
    
    TElem temp;
    
    for (int i = 0; i < m.size(); i++) {
        for (int j = i + 1; j < m.size(); j++) {
            if (m.relation(this->elementsSorted[i].first, this->elementsSorted[j].first)) {
                temp = this->elementsSorted[i];
                this->elementsSorted[i] = this->elementsSorted[j];
                this->elementsSorted[j] = temp;
            }
        }
    }
    
    this->currentIndex = 0;
}




void SortedMapIterator::first(){
    this->currentIndex = 0;
}




void SortedMapIterator::next(){
    if (this->valid()) {
        this->currentIndex++;
    } else {
        throw exception();
    }
}




bool SortedMapIterator::valid() const{
    if (this->currentIndex < map.size()) {
        return true;
    }
    return false;
}




TElem SortedMapIterator::getCurrent() const{
    if (this->valid()) {
//        cout << "Current: (" << this->elementsSorted[this->currentIndex].first << ", " << this->elementsSorted[this->currentIndex].second <<")"  << endl;
        return this->elementsSorted[this->currentIndex];
    } else {
        throw exception();
    }
}

