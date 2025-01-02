#include<bits/stdc++.h>

using namespace std;

void quemar()
{

}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;

	cin >> t;

	while(t--)
	{
		int n, q;

		cin >> n >> q;

		vector<vector<int>> adj(n);
		vector<bool> vis(n, false), quemados(n, false);

		map<int, int> mapa; // hijo: padre

		for(int i = 0, u, v; i < n - 1; i++)
		{
			cin >> u >> v;
			u--;
			v--;
			mapa[v] = u;

			adj[u].push_back(v);
		}
		
		for(int i = 0, u, x = -1; i < q; i++)
		{
			cin >> u;
			u--;
			quemados[u] = true;
			
			while(u != 0)
			{
				x = mapa[u];
				u = x;
				quemados[x] = true;
			}
		}

		int ans = 0;

		for(int i = 0; i < n; i++)
		{
			if(quemados[i])
				ans++;
		}

		cout << ans << "\n";
	}
	
	return 0;
}