#include "sorting_algorithms.h"
#include <iostream>
#include <utility>
#include <cmath>


//Bubble sort algorithm
void bubble_sort(int list[], int size){
    bool sorted;
    for(int i=0; i<size-1; i++){
        sorted = true; 
        for(int j=0; j<size-i-1; j++)
            if(list[j] > list[j+1]){
                std::swap(list[j], list[j+1]);
                sorted = false;
            }
        if(sorted) break;
    }
}


//Insertion sort algorithm
void insertion_sort(int list[], int size){
    for(int j=1; j<size; j++){
        int key = list[j];
        int i = j;
        while(i>0 and list[i-1]>key){
            list[i] = list[i-1];
            i--;
        }
        list[i]=key;
    }
}


// Merge sort algorithm
// This function only calls the recursive merge sort function for the whole array
void merge_sort(int list[], int size){
    merge_sort_recursion(list, 0, size-1);
}

void merge_sort_recursion(int list[], int left, int right){
    if(left < right){
        int middle = (left + right)/2;
        merge_sort_recursion(list, left, middle);
        merge_sort_recursion(list, middle+1, right);
        merge(list, left, middle, right);
    }
    //if not, returns recursively
}

void merge(int list[], int left, int middle, int right){
    //n1 and n2 are the lengths of the already sorted sublists
    int n1 = middle-left+1;
    int n2 = right-middle;
    //copy the pre-sorted sublists to L and R
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i]=list[left+i];
    for(int j=0; j<n2; j++)
        R[j]=list[middle+1+j];


    //Merge the L and R sorted lists
    int i=0, j=0, k=left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
            list[k++]=L[i++];
        else 
            list[k++]=R[j++];
    }

    // At most one of these two will actually do anything.
    // Copy the remaining elements of L, if there are any
    while (i < n1) 
        list[k++] = L[i++];
    // Copy the remaining elements of R, if there are any
    while (j < n2)
        list[k++] = R[j++];
}



// Heap-sort first arranges the array into a max-heap, before sorting. 
// In a max-heap, each element is greater than its 'children', LEFT and RIGHT.
// Since one property of a max-heap is that the first element is the largest,
// heap_sort swaps this element with the last element, then re-heapifies the 
// rest, recursively until the whole array is sorted
void heap_sort(int list[], int size)
{
    heap tempheap;
    tempheap.length = size;
    tempheap.nodes = list;
    tempheap.heap_size = size;
    build_max_heap(tempheap);

    for(int i=tempheap.length-1; i>=1; i--){
        std::swap(tempheap.nodes[0], tempheap.nodes[i]);
        tempheap.heap_size -= 1;
        max_heapify(tempheap, 0);
    }
}

//build_max_heap turns an array into max-heap form by repeatedly calling
//max_heapify
void build_max_heap(heap list){
    list.heap_size = list.length;
    for(int i = std::floor(list.length/2); i>=0; i--)
        max_heapify(list, i);
}

//max_heapify places the element list[index] into the subarray list[index+1...], 
//which is assumed to already be in max-heap form
void max_heapify(heap list, int index){
    int left, right, largest;

    left = LEFT(index);
    right = RIGHT(index);

    if(left < list.heap_size && list.nodes[left] > list.nodes[index])
        largest = left;
    else
        largest = index;
    
    if(right < list.heap_size && list.nodes[right] > list.nodes[largest])
        largest = right;
    
    if(largest != index){
        std::swap(list.nodes[index], list.nodes[largest]);
        max_heapify(list, largest);
    }
}


// Quick sort algorithm
// This function only calls the recursive merge sort function for the whole array
void quick_sort(int list[], int size){
    quicksort_recursion(list, 0, size-1);
}

void quicksort_recursion(int list[], int left, int right){
    int pivot;
    if(left < right){
        pivot = partition(list, left, right);
        quicksort_recursion(list, left, pivot-1);
        quicksort_recursion(list, pivot+1, right);
    }
}

// Function returns the correct position of the pivot element
int partition(int list[], int left, int right){
    // Choose the rightmost element as pivot 
    // In most cases it's a quick, safe and easy guesstimate
    int pivot, index; 
    pivot = list[right];
    index = left - 1;
    for(int i=left; i<right; i++){
        if(list[i] <= pivot){
            index++;
            std::swap(list[i], list[index]);
        }
    }
    std::swap(list[right], list[index+1]);
    return index+1;
}
