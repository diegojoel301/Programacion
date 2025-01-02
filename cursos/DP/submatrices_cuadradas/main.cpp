#include<bits/stdc++.h>

using namespace std;

int maxSubMatriz(bool mat[25][25], int N)
{
	int aux[N][N];
	
	for(int i = 0; i < N; i++)
	{
		aux[0][i] = mat[0][i];
		aux[N - 1][i] = mat[N - 1][i];
	}

	for(int i = 1; i < N - 1; i++)
	{
		aux[i][0] = mat[0][i];
		aux[i][N - 1] = mat[i][N - 1]; 
	}

	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(mat[i][j])
				aux[i][j] = 1 + min(aux[i - 1][j - 1], min(aux[i - 1][j], aux[i][j - 1]));
			else
				aux[i][j] = 0;
		}
	}

	int maximo = -1;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(maximo < aux[i][j])
				maximo = aux[i][j];
		}
	}
	
	return maximo * maximo;
}

int main()
{
	int N, t;
	cin >> t;
	while(t--)
	{
		cin >> N;
		bool mat[25][25];

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cin >> mat[i][j];
		}

		cout << maxSubMatriz(mat, N) << "\n";	
	}
	

	return 0;
}
