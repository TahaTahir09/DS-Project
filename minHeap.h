#pragma once
#include "heapItem.h"
using namespace std;
struct minHeap
{
	int size, capacity, * position; //var 'position' will be used in 3 functions as a helper
	//to get current index of node in minHeap
	heapItem** heapArray;
	minHeap(int);
	void swapHeapItem(heapItem**, heapItem**);
	void minHeapify(int);
	heapItem* extractMin();
	void decreaseKey(int v, int k); //decreases key value 'k' of vertex
	~minHeap();
};