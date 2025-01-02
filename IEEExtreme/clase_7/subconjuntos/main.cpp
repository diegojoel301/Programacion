#include<bits/stdc++.h>

using namespace std;

const int N = 25; // variable constante

int v[N]; // guardamos el conjunto
bool estado[N]; // guarda el estado del conjunto

int n; // tamaño del conjunto

void conjuntos(int pos)
{
	if(pos == n)
	{
		cout << "{";
		for(int i = 0; i < n - 1; i++)
		{
			if(estado[i])
				cout << v[i] << ", ";
		}
		cout << v[n - 1] << "}\n";
		return;
	}
	else
	{
		estado[pos] = false;
		conjuntos(pos + 1); // no tomar

		// tomando parte del conjunto

		estado[pos] = true;
		conjuntos(pos + 1); // si tomar
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	memset(estado, N, sizeof estado);
	memset(v, N, sizeof v);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> v[i];

	conjuntos(0);

	return 0;
}