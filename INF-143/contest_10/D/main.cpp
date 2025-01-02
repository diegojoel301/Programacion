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

	int t, n, m, x, y, X, Y;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		vector<vector<int>> adj(n);
		vector<bool> vis(n, false);

		while(m--)
		{
			cin >> x >> y;

			adj[x - 1].push_back(y - 1);
		}

		cin >> X >> Y;
		
		dfs(adj, vis, X - 1);
		
		if(vis[Y - 1])
			cout << "SI\n";
		else
			cout << "NO\n";
		

	}

	return 0;
}