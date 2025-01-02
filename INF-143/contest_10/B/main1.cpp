#include<bits/stdc++.h>

using namespace std;

vector<int> G[200010];
bool vis[200010];

int dfs(int u)
{
	if(vis[u])
		return 0;
	vis[u] = 1;
	int ans = 1;
	//recursividad para ver a cuantos nodos puedo llegar
	for(int v: G[u])
		ans += dfs(v);
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		for(int i = 0; i < n + 10; i++)
			G[i].clear();

		for(int i = 0; i < n; i++)
		{
			int u, v;

			cin >> u >> v;

			G[u].push_back(v);
		}

		int mx = -1;
		int id = -1;

		for(int i = 1; i <= n; i++)
		{
			memset(vis, 0, sizeof vis);
			int numNodes = dfs(i);

			if(numNodes > mx)
			{
				mx = numNodes;
				id = i;
			}
			else if(numNodes == mx)
				id = min(id, i);
		}
		cout << id << "\n";
	}

	return 0;
}