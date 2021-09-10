/*
* Purpose: Link functions
* Author: Jian Yue
* Data:   2020/08/23,revised 2020/09/10
*/

#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<cmath>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addNode(ListNode* head, int value)
{
	ListNode* p = head;
	while (p->next != nullptr)
		p = p->next;

	ListNode* newNode = new ListNode(value);
	p->next = newNode;
	return head;
}

void travelList(ListNode* head)
{
	ListNode* p = head->next;

	while (p != nullptr)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
void removeNode(ListNode* head, int del_value)
{
	ListNode* p = head;
	if (p->next == nullptr)
	{
		cout << " this is a empty link" << endl;
		return;
	}
	p = p->next;
	while (p->next != nullptr)
	{
		if (p->val == del_value)
		{
			p->val = p->next->val;
			p->next = p->next->next;
			break;
		}
		p = p->next;

	}
}

ListNode* reverseList(ListNode* head)
{

	ListNode* p = head->next;
	ListNode* temp = p->next;
	p->next = nullptr;

	while (temp != nullptr)
	{
		p = temp;
		temp = temp->next;
		p->next = head->next;
		head->next = p;
	}
	return head;
}

void InsertNode(ListNode* head, int node_value, int in_value)
{
	ListNode* p = head;
	if (p->next == nullptr)
	{
		cout << " this is a empty link" << endl;
		return;
	}
	ListNode* in_node = new ListNode(in_value);
	p = p->next;
	while (p->next != nullptr)
	{
		if (p->val == node_value)
		{
			in_node->next = p->next;
			p->next = in_node;
			break;
		}
		p = p->next;

	}
}

ListNode* createList(vector<int> nums)
{
	ListNode* dummy(0);
	ListNode* p=dummy;
	for (auto num : nums)
	{
		p->next = new ListNode(num);
		p = p->next;
	}
	return dummy->next;
}
