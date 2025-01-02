#include <bits/stdc++.h>
//contar componentes conexas

/*
########
#..#...#
####.#.#
#..#...#
########
*/

vector adj[N];
bool visited[N];

void dfs(int s)
{
	if(visited[s]) return;
	visited[s] = true;

	for(auto u: adj[s])
		dfs(u);
}

using namespace std;

int main()
{
	int comp = 0;

	for(int i = 0; i < n; i++)
	{
		if(not visited[i])
		{
			comp++;
			dfs(i);
		}
	}

	//otra forma mas simplona
	comp = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(not graph[i][j] != '#')
			{
				comp++;
				dfs(i);
			}
		}
	}
}