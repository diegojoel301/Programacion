#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y, t;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		vector<vector<int>>	adj(n);

		vector<int> v(n, -1);

		queue<int> q;

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		q.push(0);

		v[0] = 0;

		while(not q.empty())
		{
			int u = q.front();
			q.pop();

			for(int i = 0; i < adj[u].size(); i++)
			{
				if(v[adj[u][i]] == -1)
				{
					v[adj[u][i]] = v[u] + 1;
					q.push(adj[u][i]);
				}
			}
		}

		for(int i = 1; i < v.size(); i++)
			cout << v[i] << "\n";
		cout << "\n";
	}

	return 0;
}