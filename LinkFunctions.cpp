/*
* Purpose: Link functions
* Author: Jian Yue
* Data:   2020/08/23
*/
#include<iostream>
#include<string>
using std::string;
#include<vector>
using std::vector;
using namespace std;
const int Rows = 4, Cols = 3;

struct node
{
	int value;
	node *next;
	node(int x) :value(x), next(nullptr) {}
};

node* addNode(node* head, int value)
{
	node* p = head;
	while (p->next != nullptr)
		p = p->next;

	node* newNode = new node(value);
	p->next = newNode;
	return head;
}

void travelList(node* head)
{
	node* p = head->next;
	
	while (p != nullptr)
		{	
			cout << p->value << " ";
			p = p->next;
		}
	cout << endl;
	return;
}
void removeNode(node* head,int del_value)
{
	node* p = head;
	if (p->next == nullptr)
	{
		cout << " this is a empty link" << endl;
		return;
	}
	p = p->next;
	while (p->next!=nullptr)
	{
		if (p->value == del_value)
		{
			p->value = p->next->value;
			p->next = p->next->next;
			break;
		}
		p = p->next;

	}
}

node* reverseList(node* head)
{
	
	node* p = head->next;
	node* temp = p->next;
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

void InsertNode(node* head,  int node_value, int in_value)
{
	node* p = head;
	if (p->next == nullptr)
	{
		cout << " this is a empty link" << endl;
		return;
	}
	node* in_node = new node(in_value);
	p = p->next;
	while (p->next != nullptr)
	{
		if (p->value == node_value)
		{
			in_node->next = p->next;
			p->next = in_node;
			break;
		}
		p = p->next;

	}
}
int main()
{
	node* head = new node(0);
	for(int i=0;i<10;++i)
	{ 
		addNode(head, i);
	}

	travelList(head);
	removeNode(head, 5);
	travelList(head);
	InsertNode(head, 4, 5);
	travelList(head);
	node* newhead = nullptr;
	newhead = reverseList(head);
	travelList(newhead);
}
