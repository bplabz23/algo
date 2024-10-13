// C++ code to depict 
// the implementation of a max heap. 
  
#include <iostream> 
using namespace std; 
  
// A class for Max Heap. 
struct MinHeap { 
    
    int* arr;       // A pointer pointing to the elements  
    int maxSize;    // Size of array
    int heapSize;   // Actual size of heap
  


public: 
    // Constructor function. 
    MinHeap(int maxSize); 
  
    // Heapifies a sub-tree taking the 
    // given index as the root. 
    void HeapifyMin(int); 
  
    // Returns the index of the parent 
    // of the element at ith index. 
    int parent(int i) 
    { 
        return (i - 1) / 2; 
    } 
  
    // Returns the index of the left child. 
    int lChild(int i) 
    { 
        return (2 * i + 1); 
    } 
  
    // Returns the index of the 
    // right child. 
    int rChild(int i) 
    { 
        return (2 * i + 2); 
    } 
  
    // Removes the root which in this 
    // case contains the maximum element. 
    int removeMin(); 
  

    // Sort array in ascending order
    int HeapSortMin();

    void printSortedHeap(int size);


    // Returns the maximum key 
    // (key at root) from max heap. 
    int getMin() 
    { 
        return arr[0]; 
    } 
  
    int curSize() 
    { 
        return heapSize; 
    } 
  
  
    // Inserts a new key 'x' in the Max Heap. 
    void insertionMin(int x); 
}; 
  




// Constructor function builds a heap 
// from a given array a[] 
// of the specified size. 
MinHeap::MinHeap(int totSize) 
{ 
    heapSize = 0; 
    maxSize = totSize; 
    arr = new int[totSize]; 
} 
  





// Inserting a new key 'x'. 
void MinHeap::insertionMin(int x) 
{ 
    // To check whether the key 
    // can be inserted or not. 
    if (heapSize == maxSize) { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // The new key is initially 
    // inserted at the end. 
    heapSize++; 
    int i = heapSize - 1; 
    arr[i] = x; 
  
    // The max heap property is checked 
    // and if violation occurs, 
    // it is restored. 
    while (i != 0 && arr[parent(i)] > arr[i]) { 
        swap(arr[i], arr[parent(i)]); 
        i = parent(i); 
    } 
} 
  







// To remove the root node which contains 
// the minimum element of the Max Heap. 
int MinHeap::removeMin() 
{ 
    // Checking whether the heap array 
    // is empty or not. 
    if (heapSize <= 0)              // Already sorted cases 
        return 0; 
    if (heapSize == 1) {        
        heapSize--; 
        return 0; 
    } 
  
    // Storing the smallest element 
    // to remove it. 
    int root = arr[0];                      
    arr[0] = arr[heapSize - 1]; 
    heapSize--; 
  
    arr[heapSize] = root;           // Store this root just outside the heap, for the use of heapsort

    // To restore the property 
    // of the Min heap. 
    HeapifyMin(0); 
    return 0;
  
} 
  




void MinHeap::printSortedHeap(int size)
{
    cout << "\nSorted Heap: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}




  
// To heapify the subtree this method 
// is called recursively 
void MinHeap::HeapifyMin(int i) 
{ 
    int l = lChild(i); 
    int r = rChild(i); 
    int smallest = i; 
    if (l < heapSize && arr[l] < arr[i])            // swap left child w/ root if it is in the heap and lesser
        smallest = l; 
    if (r < heapSize && arr[r] < arr[smallest])      // else if right child is smaller, swap it with root
        smallest = r; 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
        HeapifyMin(smallest);                       // If we perform a swap, check that heap property is still satisfied
    } 
} 






    // sort the array in ascending order
    // Returns the number of elements from [0, n-1] that are sorted (actually in heap)
    int MinHeap::HeapSortMin()
    {
        // Make a copy of the heap size
        int sortedSize = curSize();

        // While heap not empty
        while (heapSize > 0)
        {
            removeMin();
        }
        
        // Note: This operation is in-place, but note that if the array is modified, the results will be lost
        return sortedSize;
    }








// Driver program to test above functions. 
int main() 
{ 
    // Assuming the maximum size of the heap to be 15. 
    MinHeap h(15); 




    // We will enter in this data into the heap
    int temp[] = {3,10,12,8,2,14};

    cout << "Inserting into heap: ";

    for (int i = 0; i < 6; i++)
    {
        cout << temp[i] << " ";
        h.insertionMin( temp[i] ); 
    }

    cout << endl;
  

    // Printing the current size 
    // of the heap. 
    cout << "The current size of the heap is "
         << h.curSize() << "\n"; 
  

    // Printing the root element which is 
    // actually the min element. 
    cout << "The current maximum element is " << h.getMin() 
         << "\n" << endl << endl;; 
  

    // print sorted heap
    int size = h.HeapSortMin();\
    h.printSortedHeap(size);


/*
    // Inserting 2 new keys into the heap. 
    h.insertionMin(15); 
    h.insertionMin(5); 
    cout << "The current size of the heap is "
         << h.curSize() << "\n"; 
    cout << "The current maximum element is " << h.getMin() 
         << "\n"; 
*/
    return 0; 
}
