#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];

int in_degree[N]; // grado de entrada

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;

	while(cin >> n >> m)
	{
		for(int i = 0; i < n; i++)
			G[i].clear();

		memset(in_degree, 0, sizeof in_degree);

		for(int i = 0; i < m; i++)
		{
			int u, v;

			cin >> u >> v;
			G[u].push_back(v); // u -----> v
			in_degree[v]++; // a v esta entrando una arista
		}
		// BFS
		queue<int> q;
		for(int i = 0; i < n; i++)
		{
			if(in_degree[i] == 0) // los de grado 0
				q.push(i);
		}
		vector<int> toposort; toposort.clear();

		while(not q.empty())
		{
			int u = q.front();
			toposort.push_back(u);
			q.pop();

			for(int v: G[u]) // for(int i = 0; i < G[u].size(); i++)
			{
				in_degree[v]--;
				if(in_degree[v] == 0)
					q.push(v);
			}
		}
		for(int u: toposort)
			cout << u << " ";
		cout << "\n";
	}

	return 0;
}