#pragma once
#include "list.h"
#include "minHeap.h"
using namespace std;
class graph
{
	int nOfVertices;
	list* adjList;
public:
	graph(int n) { nOfVertices = n, adjList = new list[nOfVertices]; }
	void insertEdge(int, int, int); //makes 'link' from both vertices
	//to each other
	int getNOfVertices() { return nOfVertices; }
	int* make_MST_via_PrimAlgo();
	int getWeightOfEdge(int x, int y); //returns weight of edge xy
	void printMST(int[]); //prints all edges of MST along with their weight
	int getMSTWeight(int[]); //returns total weight of all edges in MST
	~graph() { delete[]adjList; }
};