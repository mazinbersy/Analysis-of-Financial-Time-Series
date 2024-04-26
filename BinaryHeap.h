#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include<vector>
using namespace std;

template <class T>
class BinaryHeap
{
private:
    int size; // Size of the heap
    T* array; // Dynamic array to store heap elements

public:
    // Constructor
    BinaryHeap(int);

    // Heapify operations
    void minHeapify(int, int);
    void maxHeapify(int, int);

    // Build heap from an array
    void BuildMaxHeap(vector<T> a);
    void BuildMinHeap(vector<T> a);

    // Delete minimum and maximum nodes
    T deleteMinNode();
    T deleteMaxNode();

    // Return the heap array
    T* returnHeap();

    // Print the heap array
    void printHeap();

    // Destructor
    ~BinaryHeap();
};


template<class T>
BinaryHeap<T>::BinaryHeap(int s)
{
    size = s; // Initialize size
    array = new T[size]; // Allocate memory for array
}

template<class T>
void BinaryHeap<T>::minHeapify(int index, int heapSize)
{
    // Calculate left and right child indices
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int smallest = index; // Assume current index as the smallest

    // Find the smallest element among parent, left child, and right child
    if (leftChild <= heapSize && array[leftChild] < array[index])
        smallest = leftChild;

    if (rightChild <= heapSize && array[rightChild] < array[smallest])
        smallest = rightChild;

    // If smallest is not the parent, swap and recursively heapify
    if (smallest != index) {
        swap(array[index], array[smallest]);
        minHeapify(smallest, heapSize);
    }
}

template<class T>
void BinaryHeap<T>::maxHeapify(int index, int heapSize)
{
    // Calculate left and right child indices
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;
    int largest = index; // Assume current index as the largest

    // Find the largest element among parent, left child, and right child
    if (leftChild <= heapSize && array[leftChild] > array[index])
        largest = leftChild;

    if (rightChild <= heapSize && array[rightChild] > array[largest])
        largest = rightChild;

    // If largest is not the parent, swap and recursively heapify
    if (largest != index) {
        swap(array[index], array[largest]);
        maxHeapify(largest, heapSize);
    }
}

template<class T>
void BinaryHeap<T>::BuildMaxHeap(vector<T> a)
{
    size = a.size(); // Update heap size
    for (int i = 0; i < size; i++)
        array[i + 1] = a[i]; // Copy elements to heap array

    // Heapify from the last non-leaf node
    for (int i = size / 2; i >= 1; i--)
        maxHeapify(i, size);
}

template<class T>
void BinaryHeap<T>::BuildMinHeap(vector<T> a)
{
    size = a.size(); // Update heap size
    for (int i = 0; i < size; i++)
        array[i + 1] = a[i]; // Copy elements to heap array

    // Heapify from the last non-leaf node
    for (int i = size / 2; i >= 1; i--)
        minHeapify(i, size);
}

template<class T>
T BinaryHeap<T>::deleteMinNode()
{
    // Check if heap is empty
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
    // Check if heap is empty
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
T* BinaryHeap<T>::returnHeap()
{
    return array; // Return the heap array
}

template<class T>
void BinaryHeap<T>::printHeap()
{
    for (int i = 1; i <= size; i++) {
        cout << array[i] << " "; // Print each element of the heap
    }
    cout << endl;
}

template<class T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] array; // Deallocate memory for heap array
}

#endif // BINARYHEAP_H
