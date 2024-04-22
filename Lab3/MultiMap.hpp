//
//  MultiMap.hpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#ifndef MultiMap_hpp
#define MultiMap_hpp
#include <vector>
#include <utility>
#include <stdio.h>

using namespace std;

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)

class MultiMapIterator;

class MultiMap {
    friend class MultiMapIterator;
    
private:

    int capacity;
    int head;
    int firstEmpty;
    int nrElements;
    TElem* elements;
    int* next;
    
    
public:
    //constructor
    MultiMap();

    //adds a key value pair to the multimap
    void add(TKey c, TValue v);

    //removes a key value pair from the multimap
    //returns true if the pair was removed (if it was in the multimap) and false otherwise
    bool remove(TKey c, TValue v);

    //returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
    vector<TValue> search(TKey c) const;

    //returns the number of pairs from the multimap
    int size() const;

    //checks whether the multimap is empty
    bool isEmpty() const;

    //returns an iterator for the multimap
    MultiMapIterator iterator() const;
    
    void toString();
    
    
    int getNumberOfValues(TKey key);
    
    
    unsigned long getNumberOfValuesWithSearch(TKey key);

    //descturctor
    ~MultiMap();
};


#endif /* MultiMap_hpp */
