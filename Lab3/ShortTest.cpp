//
//  ShortTest.cpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#include "ShortTest.hpp"
#include "MultiMap.hpp"
#include "MultiMapIterator.hpp"
#include <assert.h>
#include <vector>
#include <iostream>

void testAll() {
    MultiMap m;
    m.add(1, 100);
    m.add(2, 200);
    m.add(3, 300);
    m.add(1, 500);
    m.add(2, 600);
    m.add(4, 800);
    
    assert(m.getNumberOfValues(1) == 2);
    assert(m.getNumberOfValues(2) == 2);
    assert(m.getNumberOfValues(4) == 1);
    assert(m.getNumberOfValues(5) == 0);
    
    assert(m.getNumberOfValuesWithSearch(1) == 2);
    assert(m.getNumberOfValuesWithSearch(2) == 2);
    assert(m.getNumberOfValuesWithSearch(4) == 1);
//    m.toString();
    assert(m.size() == 6);
    assert(m.remove(5, 600) == false);
    
    vector<TValue> v;
    
    v=m.search(1);
    assert(v.size()==2);
    assert(m.remove(1, 500) == true);
    
    v=m.search(1);
    assert(v.size()==1);

    assert(m.size() == 5);

    
    v=m.search(6);
    assert(v.size()==0);

    assert(m.isEmpty() == false);

    MultiMapIterator im = m.iterator();
    assert(im.valid() == true);
    while (im.valid()) {
        im.getCurrent();
        im.next();
    }
    assert(im.valid() == false);
    im.first();
    assert(im.valid() == true);
}
