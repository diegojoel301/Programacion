#include<bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
	if(n <= 1)
		return false;

	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

void dfs(const vector<vector<int>> &adj, vector<bool> &vis, int node)
{
	if(not vis[node])
	{
		vis[node] = true;
		//cout << node << " ";
		for(int i = 0; i < adj[node].size(); i++)
			dfs(adj, vis, adj[node][i]);
	}
	else
		return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b;

	while(true)
	{
		cin >> a >> b;

		if(a == 0 and b == 0)
			break;

		vector<vector<int>> adj(b + 1); // abs(a - b) + 1
		vector<bool> vis(b + 1, false);

		for(int i = a; i <= b; i++)
		{
			for(int j = i + 1; j <= b; j++)
			{
				if(is_prime(i + j))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
			
		int cc = 0;

		for(int i = a; i < adj.size(); i++)
		{
			if(not vis[i])
			{
				//cout << i << ": ";
				dfs(adj, vis, i);
				cc++;
				//cout << "\n";
			}
		}
		

		cout << cc << "\n";
	}

	return 0;
}