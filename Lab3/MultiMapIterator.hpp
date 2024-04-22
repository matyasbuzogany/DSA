//
//  MultiMapIterator.hpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#ifndef MultiMapIterator_hpp
#define MultiMapIterator_hpp

#include "MultiMap.hpp"
#include <stdio.h>

class MultiMap;

class MultiMapIterator {
    friend class MultiMap;
    
private:
    const MultiMap& col;
    int currentIndex;
    int head;
    
    MultiMapIterator(const MultiMap& c);
    
public:
    TElem getCurrent() const;
    bool valid() const;
    void next();
    void first();
};

#endif /* MultiMapIterator_hpp */
