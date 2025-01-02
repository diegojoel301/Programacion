#include<bits/stdc++.h>

using namespace std;

void bfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<vector<int>> &tree)
{
	queue<int> q;

	visited[node] = true;

	q.push(node);

	while(not q.empty())
	{
		node = q.front();
		q.pop();

		for(int child: graph[node]) // iterar los hijos de un nodo
		{
			if(not visited[child])
			{
				tree[node].push_back(child);
				visited[child] = true;
				q.push(child);
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n_vertex, n_edges, v1, v2;

	cin >> n_vertex;

	vector<vector<int>> graph(n_vertex);
	vector<vector<int>> tree(n_vertex);
	vector<bool> visited(n_vertex, false);

	cin >> n_edges;

	while(n_edges--)
	{
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}

	bfs(0, graph, visited, tree);

	for(int node = 0; node < n_vertex; node++)
	{
		cout << node << ": ";
		for(int child: tree[node])
			cout << child << " ";
		cout << "\n";
	}


	return 0;
}