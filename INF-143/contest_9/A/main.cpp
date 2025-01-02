#include<bits/stdc++.h>

using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &vis)
{
	if(not vis[node])
	{
		vis[node] = true;
		//cout << (char)node << "\n";

		for(int i = 0; i < adj[node].size(); i++)
			dfs(adj[node][i], adj, vis);
	}
	else
		return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int n;

	cin >> n;

	string cad, aux;
	
	while(n--)
	{
		char car;
		cin >> car;

		cin.ignore();	

		int num = car - 'A' + 1;

		vector<vector<int>> adj(num);
		vector<bool> vis(num, false);

		while(getline(cin, cad) and cad != "")
		{	
			adj[cad[0] - 'A'].push_back(cad[1] - 'A');
			adj[cad[1] - 'A'].push_back(cad[0] - 'A');
		}
		
		int c = 0;

		for(int i = 0; i < adj.size(); i++)
		{
			if(not vis[i])
			{
				dfs(i, adj, vis);
				//cout << "\n";
				c++;
			}
	
		}

		cout << c << "\n";

		if(n)
			cout << "\n";

	}

	return 0;
}