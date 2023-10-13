#include "LList.cpp"
#include<iostream>
#include<stdio.h>
using namespace std;

typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

elem_link1<int>* Point(int a, IntGraph &g)
{
	g.IterStart();
	elem_link1<IntList> *p;
	elem_link1<int> *q;
	do
	{
		p = g.Iter();
		p->inf.IterStart();
		q = p->inf.Iter();
	} while (q->inf != a);
	return q;
}

void AddTop(int a, IntGraph &g)
{
	IntList l;
	l.ToEnd(a);
	g.ToEnd(l);
}

void AddRib(int a, int b, IntGraph &g)
{
	elem_link1<int> *q = Point(a, g), *p;
	while(q->link) q = q->link;
	p = new elem_link1<int>;
	p->inf = b;
	p->link = NULL;
	q->link = p;
}

void create_graph(IntGraph &g)
{
	char c;
	do
	{
		cout << "top of graph: ";
		int x;
		cin >> x;
		AddTop(x, g);
		cout << "Top y/n? ";
		cin >> c;
	} while (c == 'y');
	cout << "Ribs: \n";
	do
	{
		cout << "start top: ";
		int x;
		cin >> x;
		cout << "end top: ";
		int y;
		cin >> y;
		AddRib(x, y, g);
		cout << "next: y/n? ";
		cin >> c;
	}
	while (c == 'y');
}

void LList<IntList>::print()
{
	elem_link1<IntList> *p = Start;
	while (p)
	{
		p->inf.print();
		p = p->link;
	}
	cout << endl;
}

