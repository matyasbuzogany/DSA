//
//  SetIterator.hpp
//  Lab2
//
//  Created by Matyas Buzogany on 14.03.2021.
//

#ifndef SetIterator_hpp
#define SetIterator_hpp

#include <stdio.h>
#include "Set.hpp"


class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set;
    SetIterator(const Set& s);

    Node* currentNode;
    Node* head;

public:
    void first();
    void next();
    TElem getCurrent();
    bool valid() const;
};

#endif /* SetIterator_hpp */
