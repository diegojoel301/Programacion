#include<iostream>

using namespace std;

bool esVacia(int tope)
{
	if(tope == 0)
		return true;
	return false;
}

bool esLlena(int tope, int max)
{
	if(tope == max)
		return true;
	return false;
}

void adicionar(int tope, int max, int x, int pila[101])
{
	if(not esLlena(tope, max))
	{
		tope = tope + 1;
		pila[tope] = x;
	}
	else
		cout << "Pila llena\n";
}

int eliminar(int tope, int max, int pila[101])
{
	int x = -1;
	if(not esVacia(tope))
	{
		x = pila[tope];
		tope = tope - 1;
	}
	else
		cout << "Pila vacia\n";
	return x;
}

void mostrar(int tope, int max, int pila[101])
{
	while(not esVacia(tope))
	{
		int elemento = eliminar(tope, max, pila);
		cout << elemento << "\n";
	}
}

int main()
{
	int max = 100, tope = 0;
	int v[max + 1];

	adicionar(tope, max, 1, v);
	adicionar(tope, max, 2, v);
	adicionar(tope, max, 3, v);
	adicionar(tope, max, 4, v);

	cout << eliminar(tope, max, v);


	return 0;
}