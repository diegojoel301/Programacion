#include<bits/stdc++.h>

using namespace std;

int p[5000];
void init()
{
	for(int i = 0; i < 5000; i++)
		p[i] = i;
}

void find(int x)
{
	return x == p[x] ? x: p[x] = find(p[x]);
}

void Union(int x, int y)
{
	p[find(y)] = find(x);
}

int main()
{
	int t;
	cin >> t;

	int k = 1;

	while(t--)
	{
		int n, r;
		cin >> n >> r;

		vector<pair<int, int>> puntos;

		for(int i = 0; i < n; i++)
		{
			int x, y;

			cin >> x >> y;

			puntos.push_back({x, y});
		}

		auto distancia = [&] (pair<int, int> a, pair<int, int> b)
		{
			return sqrt(1.*(a.first - b.first) * (a.first - b.first) + 1.*(a.second - b.second) * (a.second - b.second));
		};
		//w u v
		vector<pair<long double, pair<int, int>>> edges;

		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				long double dis = distancia(puntos[i], puntos[j]);
				edges.push_back({dis, {i, j}});
			}
		}
		
		// algoritmo de kruskal
		UF U;
		UF U2;
		U.init();

		sort(edges.begin(), edges.end());

		long double r1 = 0, r2 = 0;

		for(int i = 0; i < edges.size(); i++)
		{
			long double w = edges[i].first;
			int u = edges[i].second.first;
			int v = edges[i].second.second;

			if(U.find(u) != U.find(v))
			{
				U.Union(u, v);
				if(w <= r)
					r1 += w;
				else
					r2 += w;

				if(w <= r)
				{
					if(U2.find(u) != U2.find(v))
						U2.Union(u, v);
				}
			}

		}

		// termina kruskal
		int cnt = 0;

		for(int i = 0; i < n; i++)
		{
			cnt += U2.p[i] == i;
		}

		cout << "Case #" << k++ << ": ";
		cout << cnt << (int)r1 << " " << (int)r2 << "\n";

	}

	return 0;
}