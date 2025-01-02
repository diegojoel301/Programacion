#include<bits/stdc++.h>

using namespace std;

int main()
{
	//O(n + m) ~ O(n)

	string a, b;

	cin >> a >> b;

	int n = a.size();
	int m = b.size();

	string preffix = "";

	int j = 0; // puntero dinamico

	for(int i = 0; i < n; i++) //i es el puntero estatico en cada posicion
	{
		while(j < m and a[i] != b[j])
			j++;

		if(j == m) //verificamos si termino de recorrer la cadena b (m es la longitud de la cadena b)
			break;

		preffix.push_back(b[j]); // o preffix.push_back(a[i])
		j++;
	}

	cout << preffix << "\n";

	return 0;
}