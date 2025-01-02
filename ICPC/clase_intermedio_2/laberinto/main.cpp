#include<bits/stdc++.h>

using namespace std;

const int N = 10 + 5;

char A[N][N];
bool estado[N][N];
int n, m;

void backtracking(int i, int j)
{
	if(i == n - 1 and j == m - 1)
	{
		cout << "Existe un camino\n";
		estado[0][0] = 1;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(estado[i][j])
					cout << "*";
				else
					cout << A[i][j];
			}
			cout << "\n";
		}
		
		return;
	}

	// ir abajo
	if(i + 1 < n and A[i + 1][j] != '#')
	{
		estado[i + 1][j] = true;
		backtracking(i + 1, j);
		estado[i + 1][j] = false;
	}

	// ir a la derecha
	if(j + 1 < m and A[i][j + 1] != '#')
	{
		estado[i][j + 1] = true;
		backtracking(i, j + 1);
		estado[i][j + 1] = false;
	}
}

int main()
{

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> A[i][j];
	backtracking(0, 0);
	return 0;
}