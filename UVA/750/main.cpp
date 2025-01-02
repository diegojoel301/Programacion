#include<bits/stdc++.h>

using namespace std;

const int N = 8;

int soluciones[92][N][N], pos = 0;

int tabla[N][N];

void queens(int y, bool col[], bool diag1[], bool diag2[])
{
	if(y == N)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				soluciones[pos][i][j] = tabla[i][j];
		}
		pos++;
		return;
	}
	for(int x = 0; x < N; x++)
	{
		if(col[x] or diag1[x + y] or diag2[x - y + N - 1]) continue;

		col[x] = diag1[x + y] = diag2[x - y + N - 1] = 1;
		tabla[y][x] = 1;
		queens(y + 1, col, diag1, diag2);
		tabla[y][x] = 0;
		col[x] = diag1[x + y] = diag2[x - y + N - 1] = 0;

	}
}

int main()
{
	bool col[N], diag1[2*N - 1], diag2[2*N - 1];
	memset(col, false, sizeof col);
	memset(diag1, false, sizeof diag1);
	memset(diag2, false, sizeof diag2);	

	queens(0, col, diag1, diag2);

	int x, y, T;

	cin >> T;

	while(T--)
	{
		cin >> x >> y;

		x--;
		y--;

		vector<vector<int>> vcolumn;

		for(int k = 0; k < 92; k++)
		{
			if(soluciones[k][x][y] == 1)
			{
				vector<int> vcolumnp(8);

				for(int i = 0; i < N; i++)
				{
					for(int j = 0; j < N; j++)
					{
						if(soluciones[k][i][j] == 1)
						{
							vcolumnp[j] = i + 1;
							break;
						}

					}
				}

				vcolumn.push_back(vcolumnp);
			}
		}
		sort(vcolumn.begin(), vcolumn.end());

		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
		
		for(int i = 0; i < vcolumn.size(); i++)
		{
			if(i < 9)
				printf(" %d     ", i + 1);
			else
				printf("%d     ", i + 1);
			for(int j = 0; j < vcolumn[i].size(); j++)
				printf(" %d", vcolumn[i][j]);
			cout << "\n";
		}
		if(T)
			cout << "\n";
	}

	return 0;
}