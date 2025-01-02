#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m; // filas, columnas
	cin >> n >> m;

	int A[n][m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> A[i][j];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << "\n"; .
	}

	return 0;
}