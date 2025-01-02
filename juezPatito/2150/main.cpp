#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	if(x > 0)
		return (x % 10) + f(x / 10);
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int casos_prueba, n, k, suma, cantidad_digitos;

	cin >> casos_prueba;

	while(casos_prueba--)
	{
		cin >> n >> k;

		while(k--)
		{
			suma = f(f(f(n)));
			cantidad_digitos = log10(n);
			n = n / 10;
			n = (suma * pow(10, cantidad_digitos)) + n;
		}
		cout << n << "\n";
	}
	return 0;
}