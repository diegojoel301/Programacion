#include<bits/stdc++.h>

using namespace std;

const int M = 1000;

char mat[M][M];
bool vis[M][M];
int N, xo, yo, xf, yf;
int rows[] = {-1, 0, 0, 1};
int cols[] = {0, -1, 1, 0};

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

int bfs()
{
	if(not vis[xo][yo] or not mat[xf][yf])
		return -1;

	bool visi[N][N];

	memset(visi, false, sizeof(visi[0][0]) * N * N);

	visi[xo][yo] = true;

	queue<tuple<int , int, int>> q; // tuple<x, y, distance>

	q.push(make_tuple(xo, yo, 0));

	while(not q.empty())
	{
		tuple<int, int, int> node = q.front();

		if(get<0>(node) == xf and get<1>(node) == yf)
		{
			cout << "Camino\n";
			//return get<2>(node);
		}

		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int row = get<0>(node) + rows[i];
			int col = get<1>(node) + cols[i];

			if(verifica(row, col) and vis[row][col] and not visi[row][col])
			{
				visi[row][col] = true;
				q.push(make_tuple(row, col, get<2>(node) + 1));
			}
		}
	}

	return -1;

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

		int ans = bfs();
		cout << "\n";
		/*
		if(ans != -1)
			cout << "HAY RUTA POSIBLE CON DISTANCIA " << ans << "\n";
		else
			cout << "NO HAY RUTA POSIBLE\n";
		*/
	}

	return 0;
}