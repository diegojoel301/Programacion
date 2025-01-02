#include<bits/stdc++.h>

using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;

char mat[105][105];

bool verifica(int x, int y)
{
	return x >= 0 and x < n and y >= 0 and y < m;
}

bool f(int x, int y)
{
	int c = 0;

	for(int i = 0; i < 8; i++)
	{
		if(verifica(x + dx[i], y + dy[i]))
		{
			if(mat[x + dx[i]][y + dy[i]] == '*')
				c++;
		}
	}

	return c == ((int)mat[x][y] - 48);
}

bool g(int x, int y)
{
	int c = 0;

	for(int i = 0; i < 8; i++)
	{
		if(verifica(x + dx[i], y + dy[i]))
		{
			if(mat[x + dx[i]][y + dy[i]] == '*')
				c++;
		}
	}

	return c == 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];
	}

	bool flag = true;

	for(int i = 0; i < n and flag; i++)
	{
		for(int j = 0; j < m and flag; j++)
		{
			if(mat[i][j] == '.')
				flag = g(i, j);
			else if(mat[i][j] != '*')
				flag = f(i, j);
		}
	}


	if(flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}