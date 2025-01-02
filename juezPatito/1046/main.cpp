#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, type, x;

	while(cin >> n)
	{
		stack<int> pila;
		queue<int> cola;
		priority_queue<int> cola_prioridad;
		bool ver_pila = true, ver_cola = true, ver_cola_prioridad = true;
		
		for(int i = 0; i < n; i++)
		{
			cin >> type >> x;

			if(type == 1)
			{
				pila.push(x);
				cola.push(x);
				cola_prioridad.push(x);
			}
			else
			{
				if(pila.top() != x)
					ver_pila = false;

				if(cola.front() != x)
					ver_cola = false;

				if(cola_prioridad.top() != x)
					ver_cola_prioridad = false;

				pila.pop();
				cola.pop();
				cola_prioridad.pop();
			}
		}

		if(not (ver_pila or ver_cola or ver_cola_prioridad))
			cout << "impossible\n";
		else
		{
			if((ver_pila and ver_cola) or (ver_pila and ver_cola_prioridad) or (ver_cola_prioridad and ver_cola))
				cout << "not sure\n";
			else
			{
				if(ver_pila)
					cout << "stack\n";
				if(ver_cola)
					cout << "queue\n";
				if(ver_cola_prioridad)
					cout << "priority queue\n";
			}
		}
	}
	return 0;
}