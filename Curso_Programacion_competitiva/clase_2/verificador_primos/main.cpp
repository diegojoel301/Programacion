#include<bits/stdc++.h>

using namespace std;

int main()
{
	// verificador de primos

	int x;

	cin >> x;

	int contador_zeros = 0;

	for(int i = 1; i <= x; i++)
	{
		if(x % i == 0) // el resto de la division entre x y i es cero?
		{
			contador_zeros++;
		}
	}

	if(contador_zeros == 2) // los divisores de x son igual a 2?
	{
		cout << "Es primo\n";
	}
	else
	{
		cout << "No es primo\n";
	}

	return 0;
}
