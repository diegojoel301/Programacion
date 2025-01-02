#include<bits/stdc++.h>
#define N 10
using namespace std;

int n, m, k;

char A[N][N];
bool vis[N][N], state = false;

bool verifica(int x, int y)
{
	return x >= 0 and x < n and y >= 0 and y < m;
}

void dfs(int x, int y)
{
	if(A[x][y] == 'C')
	{
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				count += vis[i][j];
				//cout << vis[i][j];
			}
			//cout << "\n";
		}
		if(count <= k)
			state = true;
	}

	if(verifica(x + 1, y))
	{
		if(A[x + 1][y] != '#' and not vis[x + 1][y])
		{
			vis[x + 1][y] = true;
			dfs(x + 1, y);
			vis[x + 1][y] = false;
		}
	}
	
	if(verifica(x, y + 1))
	{
		if(A[x][y + 1] != '#' and not vis[x][y + 1])
		{
			vis[x][y + 1] = true;
			dfs(x, y + 1);
			vis[x][y + 1] = false;
		}
	}
}

int main()
{
	while(cin >> n >> m >> k)
	{
		state = false;
		memset(vis, false, sizeof vis);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
				cin >> A[i][j]; 
		}

		dfs(0, 0);

		if(state)
			cout << "Intentalo Bob\n";
		else
			cout << "Descansa Bob\n";

	}

	return 0;
}