 #include<bits/stdc++.h>

using namespace std;

int n, m, ans = 0;

void genSolucion(bool vis[15][15])
{
	cout << "path number: " << ans << "\n";
	
	for(int i = 0; i <= n + 1; i++)
	{
		for(int j = 0; j <= m + 1; j++)
		{
			if(i == 0 or j == 0 or i == n + 1 or j == m + 1)
				cout << "*";
			else if((vis[i - 1][j - 1] | 0))
				cout << ".";
			else if(not (vis[i - 1][j - 1] | 0))
				cout << "#";
		}
		cout << "\n";
	}
	
}


void DFS(int i, int j, bool vis[15][15], int M[10][10])
{
	if((i >= n or j >= m) or M[i][j] == 1)
	{
		vis[i][j] = 0;
		return;
	}
	else if(i == n - 1 and j == m - 1)
	{
		ans++;
		genSolucion(vis);
	}
	else
	{
		vis[i + 1][j] = true;
		DFS(i + 1, j, vis, M); // ABAJO
		vis[i + 1][j] = false;

		vis[i][j + 1] = true;
		DFS(i, j + 1, vis, M); // DERECHA	
		vis[i][j + 1] = false;
	}	
}

int main()
{
	freopen("input1.txt", "r", stdin);
	cin >> n >> m;

	int M[10][10];
	bool vis[15][15];
	memset(vis, 0, sizeof(vis));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cin >> M[i][j];
	}

	vis[0][0] = true;
	DFS(0, 0, vis, M);

	if(ans == 0)
		cout << "NO HAY POSIBILIDAD DE SALIR DEL LABERINTO\n";
	return 0;
}