#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<list>

using namespace std;

struct nodo
{
	int nro;
	struct nodo *sgte;
};

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor)
{
	Tlista q; 
	q = new(struct nodo);
	q->nro = valor;
	q->sgte = lista;
	lista = q; 
}
void mostrar(Tlista lista)
{
	while(lista != NULL)
	{
		cout << lista->nro << endl;
		lista = lista->sgte;
	}
}

int main()
{
	Tlista lista = NULL;
	insertarInicio(lista, 1);
	insertarInicio(lista, 2);
	insertarInicio(lista, 3);
	insertarInicio(lista, 4);
	insertarInicio(lista, 5);
	insertarInicio(lista, 6);

	mostrar(lista);
}