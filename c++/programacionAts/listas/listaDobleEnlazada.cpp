#include<iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *sig;
	Nodo *ant;
};

void adicionar(Nodo *& lista, int n)
{
	Nodo *nue = new Nodo();
	nue->dato = n;
	if(lista == NULL)
		lista = nue;
	else
	{
		nue->sig = lista;
		lista->ant = nue;
		lista = nue;
	}
}

void adicionarFinal(Nodo *& lista, int n)
{
	Nodo *nue = new Nodo();

	nue->dato = n;

	if(lista == NULL)
		lista = nue;
	else
	{
		Nodo *z = lista;

		while(z->sig != NULL)
			z = z->sig;

		z->sig = nue;
		nue->ant = z;
	}
}

void mostrar(Nodo *& lista)
{
	Nodo *r = lista;

	while(r != NULL)
	{
		cout << r->dato << " ";
		r = r->sig;
	}
	cout << "\n";
}

int main()
{
	Nodo *LDoble = NULL;

	adicionar(LDoble, 4);
	adicionar(LDoble, 3);
	adicionar(LDoble, 2);
	adicionar(LDoble, 4);
	adicionar(LDoble, 1);

	adicionarFinal(LDoble, 9);
	mostrar(LDoble);
}