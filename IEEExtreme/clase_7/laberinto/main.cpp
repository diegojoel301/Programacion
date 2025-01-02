#include<bits/stdc++.h>

using namespace std;

int n, m;
char A[9][9];
bool estado[9][9];

void backtracking(int i, int j)
{
	if(i == n - 1 and j == m - 1)
	{
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
		cout << "\n";
		return;
	}
	// ir abajo
	if(i + 1 < n and A[i + 1][j] != '#')
	{
		estado[i + 1][j] = 1;
		backtracking(i + 1, j);
		estado[i + 1][j] = 0;
	}

	// ir a la derecha
	if(i + 1 < n and A[i][j + 1] != '#')
	{
		estado[i][j + 1] = 1;
		backtracking(i, j + 1);
		estado[i][j + 1] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> A[i][j];
	}

	backtracking(0, 0);

	return 0;
}