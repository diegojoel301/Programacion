#include<bits/stdc++.h>

using namespace std;

int vis[101][101]={0}, i, j, cn;

char m[101][101];

bool val(int ii, int jj)
{
	return ii > -1 and jj > -1 and ii < i and jj < j;
}

void dfs(int ii, int jj)
{
	if(val(ii, jj) and m[ii][jj] == 'W' and not vis[ii][jj])
	{
		cn++;
		vis[ii][jj] = 1;
		dfs(ii - 1, jj);
		dfs(ii - 1, jj + 1);
		dfs(ii, jj + 1);
		dfs(ii + 1, jj + 1);
		dfs(ii + 1, jj);
		dfs(ii + 1, jj - 1);
		dfs(ii, jj - 1);
		dfs(ii - 1, jj - 1);
	}
}

int main()
{
	int cas, pi, pj;
	bool flag = false;

	cin >> cas;

	getchar();
	getchar();

	while(cas--)
	{
		if(ban)
			cout << "\n";
		ban = 1;
		i = 0;

		while(cin >> m[i] and strlen(m[i]) > 0)
		{
			if(i != 0)
			{
				j = strlen(m[i]);
			}

			if(m[i][0] == 'L' || m[i][0] == 'W')
				i++;
			else
			{
				cn = 0;
				memset(vis, 0, sizeof(vis));
				sscanf(m[i], "%d %d", &pi, &pj);
				dfs(pi - 1, pj - 1);
				cout << cn << "\n";
			}
		}
	}
}