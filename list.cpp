#include "list.h"
void list::insertAtStart(int x, int w)
{
	listNode* n = new listNode(x, w);
	if (!head)
		head = n;
	else
	{
		listNode* aux = head;
		n->next = aux;
		head = n;
	}
}
list::~list()
{
	while (head)
	{
		listNode* n = head->next;
		delete head;
		head = n;
	}
}