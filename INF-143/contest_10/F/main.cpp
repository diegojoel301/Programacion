#include<bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& vis, int node)
{
	vis[node] = true;

	for(int i = 0; i < adj[node].size(); i++)
	{
		if(not vis[adj[node][i]])
			dfs(adj, vis, adj[node][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	int n, m, x, y, conex = 0;

	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<bool> vis(n, false);

	while(m--)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(int i = 0; i < adj.size(); i++)
	{
		if(not vis[i])
		{
			conex++;
			dfs(adj, vis, i);
		}
	}

	cout << conex;

	return 0;
}