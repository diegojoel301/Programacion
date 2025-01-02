#include<bits/stdc++.h>

using namespace std;

const int M = 1000;

char mat[M][M];
bool vis[M][M];
int N, xo, yo, xf, yf;

bool verifica(int x, int y)
{
	return x >= 0 and y >= 0 and x < N and y < N;
}


void dfs(int x, int y)
{
	if(verifica(x, y))
	{
		if(not vis[x][y] and mat[x][y] != 'B')
		{
			vis[x][y] = true;
			//dfs(x - 1, y - 1);
			dfs(x - 1, y);
			//dfs(x - 1, y + 1);
			dfs(x, y - 1);
			dfs(x, y + 1);
			//dfs(x + 1, y - 1);
			dfs(x + 1, y);
			//dfs(x + 1, y + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	while(true)
	{
		cin >> N;

		if(N == 0)
			break;

		cin >> xo >> yo >> xf >> yf;

		memset(mat, 'B', sizeof(mat[0][0]) * M * M);
		memset(vis, false, sizeof(vis[0][0]) * M * M);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				cin >> mat[i][j];
		}

		dfs(xo, yo);

		if(vis[xf][yf])
			cout << "HAY RUTA POSIBLE\n";
		else
			cout << "NO HAY RUTA POSIBLE\n";

	}


	return 0;
}