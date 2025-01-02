#include<bits/stdc++.h>

using namespace std;

const int M = 1000;

bool mat[M + 1][M + 1];
int t, nro_nodes, nro_edges, cycles, x, y;

void counting_cycles(int node, int &cycles, int target, vector<bool>& vis)
{
	vis[node] = true;
	//cout << node << " ";
	for(int i = 0; i < nro_nodes + 1; i++)
	{
		if(mat[node][i])
		{
			if(i == target)
				cycles++;
		}

		if(mat[node][i] and not vis[i])
			counting_cycles(i, cycles, target, vis);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	cin >> t;

	while(t--)
	{
		cycles = 0;
		cin >> nro_nodes >> nro_edges;
		memset(mat, false, sizeof(mat[0][0]) * (M + 1) * (M + 1));
		vector<bool> vis(nro_nodes, false);

		while(nro_edges--)
		{
			cin >> x >> y;
			mat[x - 1][y - 1] = true;
		}

		for(int i = 0; i < nro_nodes; i++)
		{
			for(int r = 0; r < nro_nodes; r++) vis[r] = false;

			counting_cycles(i, cycles, i, vis);
		}
		
		if(cycles > 0)
			cout << "Tiene Ciclo\n";
		else
			cout << "No Tiene\n";
	}

	return 0;
}