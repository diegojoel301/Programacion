#include<bits/stdc++.h>

using namespace std;

vector<int> ListaAdj[1000];
vector<bool> visitado(1000, false);

void dfs(int u)
{
	cout << u << "\n";
	visitado[u] = true;
	for(int i = 0; i < ListaAdj[u].size(); i++) // todos los nodos a los que puedo ir desde u
	{
		int v = ListaAdj[u][i];
		if(not visitado[v])
			dfs(v);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m; //n: aristas, m: nodos
	cin >> n >> m;
	
	for(int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v; // u ---> v
		ListaAdj[u].push_back(v);
	}
	dfs(0);

	return 0;
}