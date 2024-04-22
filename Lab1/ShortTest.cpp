//
//  ShortTest.cpp
//  Lab1
//
//  Created by Matyas Buzogany on 27.02.2021.
//

#include "ShortTest.hpp"
#include "Bag.hpp"
#include "BagIterator.hpp"
#include <assert.h>


void testAll() {
    Bag b;
    assert(b.isEmpty() == true);
    assert(b.size() == 0);
    b.add(5);
    b.add(1);
    b.add(10);
    b.add(7);
    b.add(1);
    b.add(11);
    b.add(1);
    assert(b.size() == 7);
    assert(b.search(10) == true);
    assert(b.search(16) == false);
    assert(b.nrOccurrences(1) == 3);
    assert(b.nrOccurrences(7) == 1);
    assert(b.remove(1) == true);
    assert(b.remove(6) == false);
    assert(b.size() == 6);
    assert(b.nrOccurrences(1) == 2);
    b.add(1);
    BagIterator it = b.iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        it.next();
    }
    std::cout << "Short test over" << std::endl;
//    std::cout << "size: " << b.size() << std::endl;
//    std::cout << "c= " << c << std::endl;
//    b.toString();
}

