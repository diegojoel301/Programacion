#include<bits/stdc++.h>

using namespace std;

long long int cuadrados(int n, int m)
{
	int sum = 0;
	for(int r = 1; r < m; r++)
		sum += (n - (r - 1)) * (m - (r - 1));
	return sum;
}

long long int rectangulosTotales(int n, int m)
{
	return ((n * m) * (n + 1) * (m + 1)) / 4;
}

long long int rectangulos(int n, int m)
{
	return abs(cuadrados(n, m) - rectangulosTotales(n, m));
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t, n, m;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		cout << rectangulosTotales(n, m) << "\n";
		cout << cuadrados(n, m) << "\n";
	}
	return 0;
}