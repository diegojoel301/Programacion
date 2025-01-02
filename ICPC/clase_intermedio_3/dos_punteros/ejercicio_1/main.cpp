#include<bits/stdc++.h>
#define PRINT(x) {for(auto d:x) cout << d << " "; cout << "\n";}
#define ALL(x) x.begin(), x.end()
using namespace std;

vector<int> ar = {7, 10, 4, 1, 9, 5, 9, 6};
int n = ar.size(), x = 12;

int busqueda_binaria(int start, int nro)
{
	int l = start, r = n - 1, m = 0;

	while(l <= r)
	{
		m = (l + r) >> 1;

		if(ar[m] < nro)
			l = m + 1;
		else
			r = m - 1;
	}
	return ar[m];
}

int main()
{

	//primer codigo de fuerza bruta
	// O(n^2)
	/*
	for(int i = 0; i < n; i++) // O(n)
	{
		for(int j = 0; j < n; j++) // O(n)
		{
			if(i == j) continue; // si i == j entonces saltar el codigo posterior y pasar a la siguiente iteracion

			if(ar[i] + ar[j] == x)
			{
				cout << ar[i] << " " << ar[j] << "\n";
				return 0;
			}
		}
	}
	*/
	//segundo codigo de fuerza bruta
	/*
	O(n^2) = O((n^2) / 2) + O(n/2)
	for(int i = 0; i < n; i++) // O(n)
	{
		for(int j = i + 1; j < n; j++) // O(n)
		{
			if(i == j) continue; // si i == j entonces saltar el codigo posterior y pasar a la siguiente iteracion

			if(ar[i] + ar[j] == x)
			{
				cout << ar[i] << " " << ar[j] << "\n";
				return 0;
			}
		}
	}
	*/
	//tercer codigo de fuerza bruta
	// O(nlog(n))
	sort(ALL(ar));
	/*
	for(int i = 0; i < n; i++)
	{
		int a = ar[i];
		int b = busqueda_binaria(i + 1, x - a);

		if(a + b == x)
		{
			cout << a << " " << b << "\n";
			return 0;
		}
	}
	*/
	//cuarto codigo de fuerza bruta
	//usando lower_bound
	//lower_bound(inicio, fin, valor_buscado)

	for(int i = 0; i < n; i++)
	{
		int a = ar[i];
		int pos = lower_bound(ar.begin() + i + 1, ar.end(), x - a) - ar.begin();
		int b = ar[pos];
		if(a + b == x)
		{
			cout << a << " " << b << "\n";
			return 0;
		}
	}	

	cout << "No se encontraron esos valores\n";
	return 0;
}