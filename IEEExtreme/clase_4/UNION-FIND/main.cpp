#include<bits/stdc++.h>

using namespace std;

// MST Minimum Spaning Tree

const int N = 1e5 + 10;

int dsu[N];

void init()
{
	for(int i = 0; i < N; i++)
		dsu[i] = i;
}

int find_set(int u)
{
	if(dsu[u] == u)
		return u;
	return dsu[u] = find_set(dsu[u]);
}

int main()
{
	int n, m;

	while(cin >> n >> m)
	{
		init();
		vector<tuple<int, int, int>> aristas; aristas.clear();

		while(m--) // u <-----> v
		{
			int u, v, w;
			cin >> u >> v >> w;
			aristas.push_back({w, u, v});
		}

		sort(aristas.begin(), aristas.end());
		int total = 0;

		for(int i = 0; i < aristas.size(); i++)
		{
			int u, v, w;
			tie(w, u, v) = aristas[i];

			int u_ = find_set(u);
			int v_ = find_set(v);

			if(u_ != v_) // si son representantes diferentes unirlos o en si verificar si estan el mismno conjunto en si si son pariticiones esvalido
			{
				dsu[u_] = v_;
				total = total + w;
				cout << u << " " << v << "\n";
			}
		}
		cout << total << "\n";


	}

	return 0;
}