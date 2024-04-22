#include "SortTest.h"
#include <chrono>

double SortTest::timeN(int N, int rlist[], int npoints) 
{
    // if the algorithm was flagged as too slow for a given input, exit
    if (tooslow_)
        return 0.0;
    double elapsed {0};
    // create a local deepcopy of appropriate length of the master list for sorting
    int *rlistclone = new int[npoints];
    for (int i=N; i; --i) {
        std::copy(rlist, &rlist[npoints], rlistclone); 
        elapsed += timeOne(rlistclone, npoints);
    }
    delete[] rlistclone;
    // is it too slow?
    tooslow_ = elapsed > slowtime_;
    return elapsed/N;
}


double SortTest::timeOne(int rlist[], int npoints) const{
    auto t1 = std::chrono::high_resolution_clock::now();
    sort_(rlist, npoints);
    auto t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
}