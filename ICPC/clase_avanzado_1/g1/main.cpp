#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>> graph, vector<bool> &visited)
{
	if(visited[node]) //nuestro caso base para que no sea infinito el recorrido
		return;

	visited[node] = true; //sino marcamos que ya visitamos dicho nodo
	for(int i = 0; i < graph[node].size(); i++) // recorremos los hijos del nodo padre (node)
	{
		cout << i << ": " << visited[i] << ", ";
		dfs(graph[node][i], graph, visited);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	// Creando las variables necesarias

	const int N = 100000;
	int n, v1, v2;

	// Grafo y vector de visitados

	vector<vector<int>> graph(N);
	vector<bool> visited(N, false);

	cin >> n;

	while(n--)
	{
		// v1 va hacia v2
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
	}

	dfs(0, graph, visited);
	/*
	cin >> n_queries;

	while(n_queries--)
	{
		cin >> q;

		if(visited[q])
			cout << "Llega\n";
		else
			cout << "No llega\n";
	}
	*/

	return 0;
}