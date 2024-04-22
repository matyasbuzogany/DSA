//
//  main.cpp
//  Lab3
//
//  Created by Matyas Buzogany on 19.04.2021.
//

#include <iostream>
#include "MultiMap.hpp"
#include "ShortTest.hpp"
#include "ExtendedTest.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "Running tests...\n";
    testAll();
    testAllExtended();
    cout << "Tests done!\n";
    return 0;
}
