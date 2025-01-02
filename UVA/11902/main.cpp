#include<bits/stdc++.h>

using namespace std;

const int tam = 100;

int t, caso = 1, n;

bool mat_adj[tam][tam];
bool soluciones[tam][tam];

void dfs(int node, vector<bool>& vis)
{
	//cout << node << " ";
	vis[node] = true;

	for(int i = 0; i < n; i++)
	{
		if(mat_adj[node][i] and not vis[i])
			dfs(i, vis);
	}
}

void dfs_sol(int node, vector<bool>& vis, int target)
{
	//cout << node << " ";
	vis[node] = true;

	if(node != target)
	{
		for(int i = 0; i < n; i++)
		{
			if(mat_adj[node][i] and not vis[i])
				dfs_sol(i, vis, target);
		}	
	}
	else
		return;
}

void limpiar(vector<bool> &vis)
{
	for(int i = 0; i < vis.size(); i++) vis[i] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input1.txt", "r", stdin);
	
	cin >> t;

	while(t--)
	{
		memset(soluciones, false, sizeof(soluciones[0][0]) * tam * tam);
		soluciones[0][0] = true;

		cin >> n;

		vector<bool> vis(n, false);
		vector<bool> excluded(n, false);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0, value; j < n; j++)
				cin >> mat_adj[i][j];
		}
		
		dfs(0, vis);
		//cout << "\n";

		for(int i = 0; i < vis.size(); i++)
		{
			//if(not vis[i]) cout << i << "\n";
			excluded[i] = not vis[i];
		}

		limpiar(vis);
		
		//cout << "\n";
		for(int target = 0; target < n; target++)
		{
			bool state = false;

			for(int i = 0; i < n and not state; i++)
			{
				if(mat_adj[target][i])
					state = true;
			}
			//cout << target << ": ";

			if(not state)
			{
				//cout << "\n";
				continue;
			}
			dfs_sol(0, vis, target);

			for(int i = 0; i < vis.size(); i++)
			{
				if(not excluded[i] and not vis[i])
				{
					soluciones[target][i] = true;

					if(target == 0)
						soluciones[i][i] = true;

					//cout << i << " ";
				}
			}
			//cout << "\n";
			limpiar(vis);
		}



		string line = "+";

		for(int i = 0; i < 2*n - 1; i++)
			line += "-";
		line += "+";

		cout << "Case " << caso << ":\n" << line << "\n";

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(soluciones[i][j])
					cout << "|Y";
				else
					cout << "|N";
			}
			cout << "|\n" << line << "\n";
		}
		caso++;
	}

	return 0;
}
