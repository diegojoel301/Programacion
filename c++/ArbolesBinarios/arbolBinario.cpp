#include<iostream>
#include<stack>

using namespace std;

struct Node
{
	Node *izq;
	Node *der;
	int date;
};

void preorden(Node *& r)
{
	if(r != NULL)
	{
		cout << r->date << " ";
		preorden(r->izq);
		preorden(r->der);
	}
}

void llenarArbol(Node *& ArbolBinario)
{
	Node *root = new Node();
	root->date = 8;

	Node *n1 = new Node();
	n1->date = 3;

	Node *n2 = new Node();
	n2->date = 10;

	Node *n3 = new Node();
	n3->date = 1;

	Node *n4 = new Node();
	n4->date = 6;

	Node *n5 = new Node();
	n5->date = 14;

	Node *n6 = new Node();
	n6->date = 4;

	Node *n7 = new Node();
	n7->date = 7;

	Node *n8 = new Node();
	n8->date = 13;

	Node *n9 = new Node();
	n9->date = 5;

	ArbolBinario = root;

	ArbolBinario->izq = n1;
	ArbolBinario->der = n2;
	ArbolBinario->izq->izq = n3;
	ArbolBinario->izq->der = n4;
	ArbolBinario->izq->der->izq = n6;
	ArbolBinario->izq->der->der = n7;
	ArbolBinario->izq->der->izq->der = n9;
	ArbolBinario->der->der = n5;
	ArbolBinario->der->der->izq = n8;
}

int main()
{
	Node *ArbolBinario = NULL;

	llenarArbol(ArbolBinario);

	preorden(ArbolBinario);	

	cout << "\n";
}