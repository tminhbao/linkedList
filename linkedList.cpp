#include <iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* next;
};
struct LIST
{
	NODE* head;
	NODE* tail;
};
NODE* getNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}
void initList(LIST& l)
{
	l.head = l.tail = NULL;
}
void addHead(LIST& l, int x)
{
	NODE* p = getNode(x);
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void addTail(LIST& l, int x)
{
	NODE* p = getNode(x);
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
void addAt(LIST& l, int x, int pos)
{
	if (pos == 0 || l.head == NULL)
		addHead(l, x);
	else
	{
		int k = 1;
		NODE* p = l.head;
		while (p != NULL && k != pos)
		{
			p = p->next;
			k++;
		}
		if (k != pos)
			addTail(l, x);
		else
		{
			NODE* temp = getNode(x);
			temp->next = p->next;
			p->next = temp;
		}
	}
}
void deleteHead(LIST& l)
{
	NODE* p;
	if (l.head == l.tail)
	{
		delete l.head;
		l.head = l.tail = NULL;
	}
	else
	{
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
void deleteTail(LIST& l)
{
	NODE* p;
	if (l.head == l.tail)
	{
		l.head = l.tail = NULL;
	}
	else
	{
		p = l.head;
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
}
void deleteAt(LIST& l, int pos)
{
	if (pos == 0 || l.head == NULL || l.head->next == NULL)
	{
		deleteHead(l);
	}
	else
	{
		int k = 1;
		NODE* p = l.head;
		while (p->next->next != NULL && k != pos)
		{
			p = p->next;
			k++;
		}
		if (k != pos)
			deleteTail(l);
		else
		{
			p->next = p->next->next;
		}
	}
}
void reverseList(LIST& l)
{
	NODE* next;
	NODE* cur = l.head;
	NODE* prev = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	l.head = prev;
}
void printList(LIST l)
{
	if (l.head == NULL)
		return;
	for (NODE* p = l.head; p != NULL; p = p->next)
	{
		cout << p->data << " ";
	}
}
int main()
{
	LIST l;
	int x;
	initList(l);
	addTail(l, 5);
	addTail(l, 3);
	addTail(l, 8);
	printList(l);
	return 0;
}
