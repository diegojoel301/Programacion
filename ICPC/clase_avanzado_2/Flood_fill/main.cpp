#include<bits/stdc++.h>

using namespace std;

// Limits N*M
// N, M < 100

const int N = 100 + 10;
int n, m; // ancho y altura

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

string str[N];

int vis[N][N];

// str[0] = "...#.#"
// str[0] = "...#.#"
// str[0] = "...#.#"

bool ok(int x, int y) // la verificacion para ue la posicion a moverse debe estar en lois limites
{
	return x >= 0 and y >= 0 and x < n and y < m;
}

int dfs(int x, int y)
{
	vis[x][y] = 1;
	int sz = 1;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		//cout << nx << " " << ny << "\n";

		if(ok(nx, ny) and vis[nx][ny] == 0 and str[nx][ny] == '.') // si esta todo bien recorre el dfs
			sz += dfs(nx, ny);
	}
	return sz;
}

int main()
{
	freopen("input.txt", "r", stdin);

	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++) cin >> str[i];

		/*
			. --> libre
			# --> pared
		*/

		int components = 0;
		memset(vis, 0, sizeof vis);
		vector<int> sz;
		sz.clear();

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(str[i][j] != '.' and vis[i][j] == 0)
				{
					components++;
					sz.push_back(dfs(i, j));
					
				}
			}
		}

		cout << components << "\n";
		for(int i = 0; i < sz.size(); i++)
			cout << sz[i] << "\n";
	}
	return 0;
}
// O(N + M)