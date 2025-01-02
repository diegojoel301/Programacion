#include<bits/stdc++.h>

using namespace std;

void mostrar(int m[5][5], int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
			cout << m[i][j] << " ";
		cout << m[i][n - 1] << "\n";
	}
}

int main()
{
	int n, e, mat[5][5], nue[5][5], aux[5][5], s;
	
	cin >> n >> e;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0, value; j < n; j++)
		{
			cin >> value;
			mat[i][j] = nue[i][j] = value;
		}
	}

	for(int u = 0; u < e - 1; u++)
	{
		aux[5][5];
		s = 0;
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				s = 0;
				for(int k = 0; k < n; k++)
					s += nue[i][k] * mat[k][j];
				aux[i][j] = s;
			}
		}

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				nue[i][j] = aux[i][j];
	}

	mostrar(nue, n);
	return 0;
}