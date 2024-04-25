#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include<vector>
using namespace std;

template <class T>
class BinaryHeap
{
private:
    int size;
    T* array;

public:
    BinaryHeap(int);
    void minHeapify(int, int);
    void maxHeapify(int, int);
    void BuildMaxHeap(vector<T> a);
    void BuildMinHeap(vector<T> a);
    T deleteMinNode();
    T deleteMaxNode();
    T* returnHeap();
    double findAverage();
    void printHeap();
    ~BinaryHeap();
};


template<class T>
BinaryHeap<T>::BinaryHeap(int s)
{
	size = s;
	array = new T[size];
}

template<class T>
void BinaryHeap<T>::minHeapify(int index, int heapSize)
{
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int smallest = index;
    

    if (leftChild <= heapSize && array[leftChild] < array[index])
        smallest = leftChild;

    if (rightChild <= heapSize && array[rightChild] < array[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(array[index], array[smallest]);
        
        minHeapify(smallest, heapSize);
    }
}

template<class T>
void BinaryHeap<T>::maxHeapify(int index, int heapSize)
{
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int smallest = index;


    if (leftChild <= heapSize && array[leftChild] > array[index])
        smallest = leftChild;

    if (rightChild <= heapSize && array[rightChild] > array[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(array[index], array[smallest]);

        maxHeapify(smallest, heapSize);
    }
}

template<class T>
void BinaryHeap<T>::BuildMaxHeap(vector<T> a)
{
    size = a.size();

    for (int i = 0; i < size; i++)
        array[i + 1] = a[i];

    for (int i = size / 2; i >= 1; i--) // Start from the last non-leaf node
        maxHeapify(i, size);
}

template<class T>
void BinaryHeap<T>::BuildMinHeap(vector<T> a)
{
    size = a.size();

    for (int i = 0; i < size; i++)
        array[i + 1] = a[i];

    for (int i = size/2; i >= 1; i--) // Start from the last non-leaf node
        minHeapify(i, size);
}

template<class T>
 T BinaryHeap<T>::deleteMinNode()
{
     if (size == 0) {
         cout << "Heap is empty. No node to delete." << endl;
         return T(); // Default constructor will be called for type T
     }

     // Store the minimum node before removal
     T minNode = array[1];

     // Replace the root (minimum) with the last element
     array[1] = array[size];
     size--;

     // Restore heap property by heapifying down
     minHeapify(1, size);

     // Return the deleted minimum node
     return minNode;
 }


 template<class T>
 T BinaryHeap<T>::deleteMaxNode()
 {
     if (size == 0) {
         cout << "Heap is empty. No node to delete." << endl;
         return T(); // Default constructor will be called for type T
     }

     // Store the maximum node before removal
     T maxNode = array[1];

     // Replace the root (maximum) with the last element
     array[1] = array[size];
     size--;

     // Restore heap property by heapifying down
     maxHeapify(1, size);

     // Return the deleted maximum node
     return maxNode;
 }

 template<class T>
 inline T* BinaryHeap<T>::returnHeap()
 {
     return array;
 }

 template<class T>
 double BinaryHeap<T>::findAverage()
 {
     int sum = 0; int count = 0;
     for (auto i : array)
     {
         sum = sum + i;
         count++;
     }
     return sum/count;
 }


template<class T>
void BinaryHeap<T>::printHeap()
{
    for (int i = 1; i <= size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<class T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] array;
}



#endif // BINARYHEAP_H
