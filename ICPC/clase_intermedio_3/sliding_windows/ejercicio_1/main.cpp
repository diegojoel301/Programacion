#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> ar = {1, 4, 0, 0, 3, 10, 5};

	int n = ar.size();

	int x = 10;

	int a = 0;
	int suma = 0;
	// O(n)
	for(int b = 0; b < n; b++)
	{
		suma += ar[b];

		if(suma > x)
		{
			while(a <= b and suma > x)
			{
				suma -= ar[a];
				a++;
			}
			//suma < x o suma <= x

			if(suma == x and a <= b) // tiene que ser una ventana aun
			{
				cout << "[" << a << ", " << b << "]\n";
				return 0;
			}
		}
	}

	cout << "No existe el subarray\n";
	return 0;
}