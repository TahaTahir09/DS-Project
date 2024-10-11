#pragma once
#include "listNode.h"
#include <iostream>
#include <string>
using namespace std;
class list
{
	listNode* head;
public:
	list() { head = nullptr; }
	void insertAtStart(int, int); //inserts listNode at start of list for quick insertion
	listNode* getHead() { return head; }
	~list();
};