#include <iostream>
#include <fstream>
#include <iomanip>  
#include <cmath>

#include "SortTest.h"
#include "sorting_algorithms.h"


void sort_by_case(std::string which, std::ofstream &resultsfile){
    // npointsmax - maximum size of array to be sorted
    // navg - how many times to sort and compute the average over?
    // npoints - number of arrays of different lengths to be sorted
    // nplist - the lengths of the different arrays to be sorted
    // sorts - an array of SortTest objects, one for each algorithm
    // The sorting algorithm (defined in sorting_algorithms) and its name
    // are passed as function pointers to the constructor

    // If additional sorting algorithms are desired:
    // add the algorithm to sorting_algorithms.cpp, and to the list below
    const int npointsmax = 100000, navg = 50, npoints = 46;
    SortTest sorts[]{ 
        { bubble_sort,    "bubble"},
        { insertion_sort, "insertion"},
        { merge_sort,     "merge"},
        { quick_sort,     "quick"},
        { heap_sort,      "heap"}
    };

    double nplist[npoints];
    nplist[0] = 1;

    // create the list of array sizes
    for(int n=0; n<5; n++) {
        for(int j=2; j<11; j++) {
            nplist[9*n + j - 1] = j * std::pow(10,n);
        }
    }
    // create the master sorted, random and reverse-sorted array
    int rlist[npointsmax];
    for(int i=0; i<npointsmax; i++) {
        if(!which.compare("Best")) rlist[i] = i/5;
        if(!which.compare("Average")) rlist[i] = rand() % (npointsmax / 5);
        if(!which.compare("Worst")) rlist[i]= (npointsmax-i-1)/5;
    }
    resultsfile << std::endl << which << " case execution time in nanoseconds:" 
              << std::endl << "Length";
    for (auto &sort : sorts) resultsfile <<  '\t' << std::setw(12) << sort.name();
    resultsfile << std::endl;
    
    for (int npointsi : nplist) { // for every existing array length
        resultsfile << std::setw(6) << npointsi;
        for (auto &sort : sorts)  //for every sorting algorithm
            resultsfile << '\t' << std::setw(12) << std::setprecision(2) << 
                        std::fixed << sort.timeN(navg, rlist, npointsi);
        resultsfile << '\n';
    }
}


int main()
{
    // Initialize the random number seed
    srand(time(0));
    // File where to write outputs
    std::ofstream resultsfile("results-comparison_sort.dat");
    // Best case = already sorted array
    sort_by_case("Best", resultsfile);
    std::cout << "Best case finished!" << std::endl;
    // Average case = random array
    sort_by_case("Average", resultsfile);
    std::cout << "Average case finished!" << std::endl;
    // Worst case = reverse sorted array
    sort_by_case("Worst", resultsfile);
    std::cout << "Worst case finished!" << std::endl;
    return 0;
}