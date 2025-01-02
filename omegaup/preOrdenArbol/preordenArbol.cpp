#include<iostream>
#include<stack>

using namespace std;

struct Nodo
{
	Nodo *izq;
	Nodo *der;
	int dato;
};

void adicionar(Nodo *& ABBusqueda, int n)
{
	Nodo *nue = new Nodo();
	nue->dato = n;

	if(ABBusqueda == NULL)
		ABBusqueda = nue;
	else
	{
		Nodo *r = ABBusqueda;

		while(r != NULL)
		{
			if(r->dato > n)
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
				if(r->dato < n)
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


void preorden(Nodo *& ABBusqueda, int k)
{
	stack<Nodo*> pila;

	Nodo *r = ABBusqueda;

	int i = 1;

	while(r != NULL or not pila.empty())
	{
		if(r != NULL)
		{
			if(i == k) cout << r->dato << "\n";
			
			i++;
			pila.push(r);
			r = r->izq;

		}
		else if(not pila.empty())
		{
			r = pila.top();
			pila.pop();
			r = r->der;
		}
		
	}
}

int main()
{
	Nodo *ABBusqueda = NULL;

	int N, M;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int elem;
		cin >> elem;

		adicionar(ABBusqueda, elem);
	}
	cin >> M;

	for(int i = 0; i < M; i++)
	{
		int k;
		cin >> k;
		preorden(ABBusqueda, k);
	}
}