#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];

int in_degree[N], vis[N]; // grado de entrada
stack<int> S;

void dfs(int u)
{
	vis[u] = 1;
	for(int v: G[u])
	{
		if(vis[v] == 0)
			dfs(v);
	}
	S.push(u);
}

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
		// DFS
		for(int i = 0; i < n; i++)
		{
			if(in_degree[i] == 0) // los de grado 0
				dfs(i);
		}

		vector<int> toposort; toposort.clear();

		while(not S.empty())
		{
			toposort.push_back(S.top());
			S.pop();
		}

		for(int u: toposort)
			cout << u << " ";
		cout << "\n";

	}

	return 0;
}