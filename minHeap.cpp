#include "minHeap.h"
minHeap::minHeap(int c)
{
	capacity = c, size = 0, position = new int[capacity];
	heapArray = new heapItem * [capacity];
	for (int i = 0; i < capacity; i++)
		heapArray[i] = nullptr;
}
void minHeap::swapHeapItem(heapItem** x, heapItem** y)
{
	heapItem* aux = *x;
	*x = *y;
	*y = aux;
}
void minHeap::minHeapify(int i)
{
	int index = i, l = 2 * i + 1, r = 2 * i + 2; //'l' represents left index
	//'r' reqresents right index
	if (l < size && heapArray[l]->key < heapArray[index]->key)
		index = l;
	if (r < size && heapArray[r]->key < heapArray[index]->key)
		index = r;
	if (index != i)
	{
		heapItem* indexItem = heapArray[index], * iItem = heapArray[i];
		//swapping positions
		position[indexItem->value] = i;
		position[iItem->value] = index;
		//
		//swapping nodes
		swapHeapItem(&heapArray[index], &heapArray[i]);
		minHeapify(index);
	}
}
heapItem* minHeap::extractMin()
{
	if (size == 0)
		return nullptr;
	heapItem* h1 = heapArray[0]; //storing 'root' node in 'h1'
	//replacing 'h1' with 'h2'
	heapItem* h2 = heapArray[size - 1];
	heapArray[0] = h2;
	//
	//updating position of h2
	position[h1->value] = size - 1;
	position[h2->value] = 0;
	//
	--size;
	minHeapify(0);
	return h1;
}
void minHeap::decreaseKey(int v, int k)
{
	int index = position[v];
	heapArray[index]->key = k;
	while (index && heapArray[index]->key < heapArray[(index - 1) / 2]->key)
	{
		//swapping current node with its parent node
		position[heapArray[index]->value] = (index - 1) / 2;
		position[heapArray[(index - 1) / 2]->value] = index;
		swapHeapItem(&heapArray[index], &heapArray[(index - 1) / 2]);
		//
		index = (index - 1) / 2; // to move to parent index
	}
}
minHeap::~minHeap()
{
	for (int i = 0; i < capacity; i++)
	{
		if (heapArray[i])
			delete heapArray[i];
	}
	delete[]heapArray;
}