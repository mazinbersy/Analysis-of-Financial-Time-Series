#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
	BinaryHeap<int> heap(10);

	vector<int> array = {3,4,6,5,8,0,7,1,2 };

	heap.BuildMaxHeap(array);
	heap.printHeap();



}
