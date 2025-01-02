#include<bits/stdc++.h>

using namespace std;

vector<int> ListaAdj[1000];
vector<bool> visitado(1000, false);

void bfs(int start)
{
	visitado.assign(1000, false);
	queue<int> Q;
	Q.push(start);
	visitado[start] = true;

	while(not Q.empty())
	{
		int u = Q.front();
		cout << u << "\n";
		Q.pop();

		for(int i = 0; i < ListaAdj[u].size(); i++)
		{
			int v = ListaAdj[u][i];

			if(not visitado[v])
			{
				Q.push(v);
				visitado[v] = true;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, u, v; //n: aristas, m: nodos
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v; // u ---> v
		ListaAdj[u].push_back(v);
	}
	bfs(0);

	return 0;
}