#include<iostream>

using namespace std;

struct Node
{
	Node *izq;
	Node *der;
	int date;
};

void adicionar(Node *& ArbolBinario, int n)
{
	Node *nue = new Node();
	nue->date = n;

	Node *r = ArbolBinario;

	if(ArbolBinario == NULL)
		ArbolBinario = nue;
	else
	{
		while(r != NULL)
		{
			if(r->date > n)
			{
				if(r->izq == NULL)
				{
					r->izq = nue;
					break;
				}
				r = r->izq;
			}
			else
			{
				if(r->date < n)
				{
					if(r->der == NULL)
					{
						r->der = nue;
						break;
					}
					r = r->der;
				}
			}
		}
	}
}

void preorden(Node *& r)
{
	if(r != NULL)
	{
		cout << r->date << "\n";
		preorden(r->izq);
		preorden(r->der);
	}
}

void posorden(Node *& r)
{
	if(r != NULL)
	{
		posorden(r->izq);
		cout << r->date << "\n";
		posorden(r->der);
	}
}

void inorden(Node *& r)
{
	if(r != NULL)
	{
		inorden(r->izq);
		inorden(r->der);
		cout << r->date << "\n";
	}
}

int main()
{
	Node *ArbolBinario = NULL;

	adicionar(ArbolBinario, 50);
	adicionar(ArbolBinario, 30);
	adicionar(ArbolBinario, 24);
	adicionar(ArbolBinario, 5);
	adicionar(ArbolBinario, 28);
	adicionar(ArbolBinario, 45);
	adicionar(ArbolBinario, 98);
	adicionar(ArbolBinario, 52);
	adicionar(ArbolBinario, 60);
	
	inorden(ArbolBinario);
	return 0;
}
