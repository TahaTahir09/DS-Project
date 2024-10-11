#include "graph.h"
void graph::insertEdge(int x, int y, int w)
{
	adjList[y].insertAtStart(x, w);
	adjList[x].insertAtStart(y, w);
}
int* graph::make_MST_via_PrimAlgo()
{
	int* MST = new int[nOfVertices];
	int* k = new int[nOfVertices]; //key values for picking minimum weight edge in cut
	minHeap* h = new minHeap(nOfVertices);
	//initializing minHeap with all vertices
	//key value of all vertices (except 0th vertex) is initially infinite
	for (int i = 1; i < nOfVertices; i++)
	{
		MST[i] = 0;
		k[i] = INT_MAX;
		h->heapArray[i] = new heapItem(i, k[i]);
		h->position[i] = i;
	}
	//
	k[0] = 0; // making key value of 0th vertex '0' so it's extracted first
	h->heapArray[0] = new heapItem(0, 0);
	h->position[0] = 0;
	h->size = nOfVertices;
	while (h->size != 0)
	{
		heapItem* min = h->extractMin();
		int num = min->value;
		//traversing through all adjacent vertices of 'num' (extracted vertex)
		//and update their key values
		listNode* aux = adjList[num].getHead();
		while (aux)
		{
			int t = aux->target;
			if (h->position[t] < h->size && aux->weight < k[t])
			{
				k[t] = aux->weight;
				MST[t] = num;
				h->decreaseKey(t, k[t]);
			}
			aux = aux->next;
		}
		//
	}
	return MST;
}
int graph::getWeightOfEdge(int x, int y)
{
	listNode* n = adjList[x].getHead();
	while (n)
	{
		if (n->target == y)
			return n->weight;
		n = n->next;
	}
}
void graph::printMST(int MST[])
{
	if (MST)
	{
		cout << "\nEdge           Weight\n";
		for (int i = 1; i < nOfVertices; ++i)
		{
			cout << MST[i] << " - " << i;
			//for symmetric spacing between edge & weight
			int x = 0;
			if (MST[i] > 9)
				x = 1;
			else if (MST[i] > 99)
				x = 2;
			else if (MST[i] > 999)
				x = 3;
			if (i > 9)
				x += 1;
			else if (i > 99)
				x += 2;
			else if (i > 999)
				x += 3;
			for (int j = 0; j < 12 - x; j++)
				cout << " ";
			//
			cout << getWeightOfEdge(MST[i], i) << endl;
		}
		cout << endl;
	}
	else
		cout << "\n<ERROR! NO MST HAS BEEN MADE YET>\n\n";
}
int graph::getMSTWeight(int MST[])
{
	int n = -1;
	if (MST)
	{
		n = 0;
		for (int i = 1; i < nOfVertices; i++)
			n += getWeightOfEdge(MST[i], i);
	}
	else
		cout << "\n<ERROR! NO MST HAS BEEN MADE YET>\n\n";
	return n;
}