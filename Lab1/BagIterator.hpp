//
//  BagIterator.hpp
//  Lab1
//
//  Created by Matyas Buzogany on 23.02.2021.
//

#include "Bag.hpp"

class BagIterator
{
    //DO NOT CHANGE THIS PART
    friend class Bag;
    
private:
    const Bag& bag;
    int index;
    int frequency;

    BagIterator(const Bag& c);
public:
    void first();
    void next();
    TElem getCurrent() const;
    bool valid() const;
};
