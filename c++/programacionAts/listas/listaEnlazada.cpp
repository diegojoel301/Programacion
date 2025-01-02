#include<iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

void insertarLista(Nodo *&lista, int n)
{
	Nodo *nuevoNodo = new Nodo(); //creamos el nuevo nodo
	nuevoNodo->dato = n; //a nuestro nuevo nodo le seteamos el dato correspondiente

	Nodo *aux1 = lista; // creamos un aux que tomara la direccion de la lista
	Nodo *aux2; //este nos servira para que nos ayuda a que la lista este ordenada

	while( (aux1 != NULL) && (aux1->dato < n)) //el aux1->dato < n es para que la lista este ordenada
	{
		aux2 = aux1;
		aux1 = aux1->siguiente; //aux = aux1.getSig() en si 
	}

	if(lista == aux1)
		lista = nuevoNodo;
	else
		aux2->siguiente = nuevoNodo; 

	nuevoNodo->siguiente = aux1;
}

void mostrar(Nodo *&lista)
{
	Nodo *r = lista;

	while(r != NULL)
	{
		cout << r->dato << " ";
		r = r->siguiente;
	}
	cout << "\n";
}
void adicionar(Nodo *& lista, int n)
{
	Nodo *w = lista;
	Nodo *nue = new Nodo();
	nue->dato = n;

	if(lista == NULL)
		lista = nue;
	else
	{
		nue->siguiente = lista;
		lista = nue;
	}
}
bool buscarElemento(Nodo *& lista, int n)
{
	Nodo *r = lista;
	bool sw = false;

	while(r != NULL)
	{
		if(r->dato == n) sw = true;
		r = r->siguiente;
	}
	return sw;
}

void mostrarRecursivo(Nodo *& r)
{
	if(r != NULL)
	{
		cout << r->dato << " ";
		mostrarRecursivo(r->siguiente);
	}
	else
		cout << "\n";
}
int main()
{
	Nodo *lista = NULL;
	int dato;
	/*
	insertarLista(lista, 2);
	insertarLista(lista, 3);
	insertarLista(lista, 1);
	insertarLista(lista, 4);
	insertarLista(lista, 5);
	*/
	adicionar(lista, 2);
	adicionar(lista, 3);
	adicionar(lista, 4);
	adicionar(lista, 1);

	
	//mostrar(lista);
	mostrarRecursivo(lista);

	if(buscarElemento(lista, 3))
		cout << "SI\n";
	else
		cout << "NO\n";
	return 0;
}
