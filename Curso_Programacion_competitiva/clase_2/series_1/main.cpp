#include<bits/stdc++.h>

using namespace std;

int main()
{
	//Serie: 2, 4, 6, 8, 10,......
	int n;

	cin >> n;

	// primera solucion

	int i = 2;

	for(int itr = 0; itr <= n; itr++)
	{
		cout << i << "\n";
		i = i + 2;
	}

	// segunda solucion (optimo)

	for(int itr = 2; itr <= 2 * n; itr = itr + 2)
		cout << itr << "\n";

	return 0;
}