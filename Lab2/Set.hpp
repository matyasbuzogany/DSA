//
//  Set.hpp
//  Lab2
//
//  Created by Matyas Buzogany on 14.03.2021.
//

#ifndef Set_hpp
#define Set_hpp

#include <stdio.h>

#define NULL_TELEM -111111
typedef int TElem;

struct Node {
    TElem value;
    struct Node *next;
};

class SetIterator;

class Set {
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

    private:
        Node* head;
        unsigned int nrElements;

    public:
        //implicit constructor
        Set();

        //adds an element to the set
        //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
        //returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;
    
    
        void toString();

        //return an iterator for the set
        SetIterator iterator() const;
    
    
    int* function(int lower, int upper);

        // destructor
        ~Set();

};

#endif /* Set_hpp */
