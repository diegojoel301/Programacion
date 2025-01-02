#include<bits/stdc++.h>

using namespace std;

void bfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &distance)
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
				distance[child] = distance[node] + 1;
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
	vector<int> distance(n_vertex, 0);
	vector<bool> visited(n_vertex, false);

	cin >> n_edges;

	while(n_edges--)
	{
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}

	bfs(0, graph, visited, distance);

	for(int i = 0; i < distance.size(); i++)
		cout << i << ": " << distance[i] << "\n";


	return 0;
}