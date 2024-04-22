//
//  SortedMap.hpp
//  Lab5
//
//  Created by Matyas Buzogany on 28.04.2021.
//

#ifndef SortedMap_hpp
#define SortedMap_hpp

#include <stdio.h>
#include <utility>

typedef int TKey;
typedef int TValue;
typedef int TFunction;

typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);


class SortedMapIterator;

typedef bool(*Relation)(TKey, TKey);

class SortedMap {
    friend class SortedMapIterator;
    
private:
    TElem* elements;
    int* nexts;
    TFunction hashFunction(TKey key) {
        return key % this->m;
    };
    int m;
    int firstFree;
    int nrElements;
    Relation relation;
    
public:
    SortedMap(Relation r);

    // adds a pair (key,value) to the map
    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
    //if the key SMes not exist, a new pair is added and the value null is returned
    TValue add(TKey c, TValue v);

    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
    TValue search(TKey c);


    //removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TVALUE otherwise
    TValue remove(TKey c);

    //returns the number of pairs (key,value) from the map
    int size() const;

    //checks whether the map is empty or not
    bool isEmpty() const;

    // return the iterator for the map
    // the iterator will return the keys following the order given by the relation
    SortedMapIterator iterator() const;
    
    void toString();

    // destructor
    ~SortedMap();
};


#endif /* SortedMap_hpp */
