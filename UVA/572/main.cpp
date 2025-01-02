#include<bits/stdc++.h>

using namespace std;

int n, m;
char grid[100][100];
bool vis[100][100];

bool verifica(int i, int j)
{
	return i < n and i >= 0 and j < m and j >= 0;
}

int c;

void DFS(int x, int y)
{
	if(verifica(x, y) and not vis[x][y] and grid[x][y] == '@')
	{
		c++;
		vis[x][y] = true;
		DFS(x - 1, y);
		DFS(x - 1, y + 1);
		DFS(x, y + 1);
		DFS(x + 1, y + 1);
		DFS(x + 1, y);		
		DFS(x + 1, y - 1);
		DFS(x, y - 1);
		DFS(x - 1, y - 1);
	}
	else
		return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input1.txt", "r", stdin);	

	while(true)
	{
		cin >> n >> m;

		memset(vis, 0, sizeof vis);
		memset(grid, '*', sizeof grid);

		if(n == 0 and m == 0)
			break;
		int ans = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				c = 0;

				if(not vis[i][j] and grid[i][j] != '*')
					DFS(i, j);
				if(c != 0)
					ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}