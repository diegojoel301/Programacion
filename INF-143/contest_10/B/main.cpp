#include<bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& vis, int node, stack<int>& s)
{
	vis[node] = true;
	s.push(node);
	//cout << node + 1 << " ";
	for(int i = 0; i < adj[node].size(); i++)
	{
		if(not vis[adj[node][i]])
			dfs(adj, vis, adj[node][i], s);
	}
}

void dfs1(const vector<vector<int>>& adj, vector<bool>& vis, int node, int& nro_nodos)
{
	vis[node] = true;
	nro_nodos++;
	//cout << node + 1 << " ";
	for(int i = 0; i < adj[node].size(); i++)
	{
		if(not vis[adj[node][i]])
			dfs1(adj, vis, adj[node][i], nro_nodos);
	}
}

void clean(stack<int> &s)
{
	while(not s.empty())
		s.pop();
}

void vaciar(stack<int>& s1, stack<int>& s2)
{
	while(not s2.empty())
	{
		s1.push(s2.top());
		s2.pop();
	}
}

void limpiar(vector<bool>& vis)
{
	for(int j = 0; j < vis.size(); j++)
		vis[j] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input2.txt", "r", stdin);

	int t, n, x, y, my, my1;

	cin >> t;

	while(t--)
	{
		cin >> n;
		vector<vector<int>> adj(n);
		vector<bool> vis(false, n);

		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			adj[x - 1].push_back(y - 1);
			//adj[y - 1].push_back(x - 1);
		}
		
		my = my1 = 0;

		stack<int> nodos, aux;

		for(int i = 0; i < adj.size(); i++)
		{
			limpiar(vis);
			
			dfs(adj, vis, i, aux);
			//cout << nodos.size() << "\n";

			if(my < aux.size())
			{
				my = aux.size();
				clean(nodos);
				vaciar(nodos, aux);
			}

			clean(aux);
		}
		
		int nro_nodos, node, ans = 9999999;

		while(not nodos.empty())
		{
			node = nodos.top();
			nodos.pop();
			nro_nodos = 0;

			//cout << node << "\n";

			limpiar(vis);

			dfs1(adj, vis, node, nro_nodos);

			//cout << nro_nodos << "\n";

			if(nro_nodos > my1)
			{
				my1 = nro_nodos;
				//cout << node << "\n";

				if(ans > node)
					ans = node;
			}
		}
		
		cout << ans + 1 << "\n";

	}

	return 0;
}