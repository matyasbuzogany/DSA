//
//  main.cpp
//  Lab1
//
//  Created by Matyas Buzogany on 23.02.2021.
//

#include <iostream>
#include "Bag.hpp"
#include "ShortTest.hpp"
#include "ExtendedTest.hpp"

using namespace std;


void difference(Bag a, Bag b) {
    
    std::pair<TElem, int>* bag1;
    std::pair<TElem, int>* bag2;
    
    bag1 = a.getElements();
    bag2 = b.getElements();
    
    int sizeA = 0;
    int sizeB = 0;
    bool found = true;
    
    while ( sizeA < a.size() ) {
        
        while( sizeB < b.size() ) {
//            cout <<"Bag1:  "<< bag1[sizeA].first << ", Bag2:  " << bag2[sizeB].first <<endl;
            if (bag1[sizeA].first != bag2[sizeB].first) {
                cout << bag1[sizeA].first << endl;
                sizeA++;
                sizeB++;
            } else {
                sizeB++;
            }
        }
        
        sizeB = 0;
        sizeA++;
    }
}

int main(int argc, const char * argv[]) {
    
    testAll();
    testAllExtended();
    

    
//    Bag a;
//    Bag b;
//    a.add(5);
//    a.add(3);
//    a.add(9);
//    a.add(4);
//
//    b.add(7);
//    b.add(4);
//    b.add(9);
////    bag1 = a.getElements();
//    difference(a, b);
    
    return 0;
}


