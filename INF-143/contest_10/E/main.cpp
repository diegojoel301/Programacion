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

	int n, m, x, y, j, k;

	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<bool> vis(n);

	while(m--)
	{
		cin >> x >> y;
		adj[x].push_back(y);
	}

	cin >> j >> k;

	dfs(adj, vis, j);

	if(vis[k])
		cout << "SI";
	else
		cout << "NO";


	return 0;
}