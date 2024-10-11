#pragma once
struct listNode
{
	int target, weight;
	listNode* next;
	listNode(int t, int w) { target = t, weight = w, next = nullptr; }
	~listNode() { next = nullptr; }
};