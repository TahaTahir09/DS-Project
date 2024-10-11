#pragma once
#include <iostream>
#include <string>
using namespace std;
struct heapItem
{
	int value, key;
	heapItem(int v, int k) { value = v, key = k; }
};
