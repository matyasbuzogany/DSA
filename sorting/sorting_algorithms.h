/*In order to be acceptable by the SortTest class,
each sorting algorithm must receive an array of integers and its length.
*/

//Bubble sort algorithm
void bubble_sort(int[], int);


//Insertion sort algorithm
void insertion_sort(int[], int);


//Merge sort algorithm
void merge(int[], int, int, int);
void merge_sort_recursion(int[], int, int);
void merge_sort(int[], int);


//Heap sort algorithm
struct heap{
        int *nodes;
        int length;
        int heap_size;
};

//These little inline functions are also used by the heap-sort algorithm
inline int PARENT(int i) {return ((i - 1) / 2);}
inline int LEFT(int i)   {return (2 * i + 1);}
inline int RIGHT(int i)  {return (2 * i + 2);}

void max_heapify(heap, int);
void build_max_heap(heap);
void heap_sort(int[], int);


//Quicksort algorithm
int partition(int[], int, int);
void quicksort_recursion(int[], int, int);
void quick_sort(int[], int);