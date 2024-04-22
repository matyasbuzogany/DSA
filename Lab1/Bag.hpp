//
//  Bag.hpp
//  Lab1
//
//  Created by Matyas Buzogany on 23.02.2021.
//

#pragma once
//DO NOT INCLUDE BAGITERATOR


//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
#include <iostream>

typedef int TElem;
class BagIterator;
class Bag {

private:
    int capacity;
    int nrElements;
    int nrPairs;
    std::pair<TElem, int>* elements;

    //DO NOT CHANGE THIS PART
    friend class BagIterator;
public:
    //constructor
    Bag();
    
    //constructor2
    Bag(int cap);
    
    //adds an element to the bag
    void add(TElem e);

    //removes one occurence of an element from a bag
    //returns true if an element was removed, false otherwise (if e was not part of the bag)
    bool remove(TElem e);

    //checks if an element appearch is the bag
    bool search(TElem e) const;

    //returns the number of occurrences for an element in the bag
    int nrOccurrences(TElem e) const;

    //returns the number of elements from the bag
    int size() const;

    //returns an iterator for this bag
    BagIterator iterator() const;

    //checks if the bag is empty
    bool isEmpty() const;
    
    //prints out the bag
    void toString();
    
    
    std::pair<TElem, int>* getElements();

    //destructor
    ~Bag();
};
