#include<bits/stdc++.h>

using namespace std;

int main()
{
	// enteros
	int n;
	int m;

	// Parte de la entrada
	cin >> n;
	cin >> m;

	// Parte de la salida

	// for (inicio; condicion; iteracion)
	/*
	for(int var = n; var <= m; var++)
	{
		cout << var << "\n";
	}
	*/

	int var = n;

	while(var <= m)
	{
		cout << var << "\n";
		var = var + 1;
	}


	return 0;
}