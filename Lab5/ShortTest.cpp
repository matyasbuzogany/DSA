//
//  ShortTest.cpp
//  Lab5
//
//  Created by Matyas Buzogany on 28.04.2021.
//

#include "ShortTest.hpp"
#include "SortedMap.hpp"
#include "SortedMapIterator.hpp"
#include <assert.h>
#include <vector>
#include <iostream>

using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}


bool relatie2(TKey cheie1, TKey cheie2) {
    if (cheie1 >= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
    SortedMap sm(relatie1);
//    assert(sm.size() == 0);
//    assert(sm.isEmpty());
//    sm.add(1,2);
//    assert(sm.size() == 1);
//    assert(!sm.isEmpty());
//    assert(sm.search(1)!=NULL_TVALUE);
//    TValue v = sm.add(1,3);
//    sm.toString();
//    assert(v == 2);
//    assert(sm.search(1) == 3);

    cout << "osztas: " << 0 % 12 << endl;
    sm.add(5, 7);
    sm.add(0, 3);
    sm.add(18, 12);
    sm.add(16, 22);
    sm.add(15, 35);
    sm.add(13, 2);
    sm.add(5,12);
    sm.add(31, 6);
    sm.add(26, 123);
    sm.toString();
//    cout << sm.remove(5) << endl;;
    cout << "Size: " <<sm.size() << endl;;
//    sm.toString();
    
    SortedMapIterator it = sm.iterator();
    it.first();
    while (it.valid()){
        TElem e = it.getCurrent();
        assert(e.second != NULL_TVALUE);
        it.next();
    }
//    assert(sm.remove(1) == 3);
//    assert(sm.isEmpty());
}
