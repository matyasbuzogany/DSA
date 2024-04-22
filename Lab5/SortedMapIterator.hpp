//
//  SortedMapIterator.hpp
//  Lab5
//
//  Created by Matyas Buzogany on 28.04.2021.
//

#ifndef SortedMapIterator_hpp
#define SortedMapIterator_hpp

#include <stdio.h>
#include "SortedMap.hpp"

class SortedMapIterator {
    friend class SortedMap;
    
private:
    const SortedMap& map;
    SortedMapIterator(const SortedMap& mapionar);
    int currentIndex;
    TElem* elementsSorted;
    
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};

#endif /* SortedMapIterator_hpp */
