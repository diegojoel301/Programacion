#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> G[n];
int estado[n]; // 0: no visitado, 1: en proceso, 2: fin
bool ciclo;

void dfs(int u)
{
	estado[u] = 1; // EN PROCESO

	for(int v: G[u]) // u ---> v
	{
		if(estado[v] == 0)
			dfs(v);
		else if(estado[v] == 1) // basicamente dice que hay un ciclo
			ciclo = true;
		estado[v] = 2;
	}
}

int main()
{

	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++)
			G[i].clear();

		while(m--)
		{
			int u, v;

			cin >> u >> v;

			G[u].push_back(v);
		}
		memset(estado, 0, sizeof estado);
		ciclo = false;
		dfs(0);
		if(ciclo)
			cout << "Existe un ciclo\n";
		else
			cout << "No existe un ciclo\n";
	}
	return 0;
}