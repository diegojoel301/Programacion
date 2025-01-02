#include<bits/stdc++.h>

using namespace std;

int Find(int x, vector<int>& padre)
{
	if(x == padre[x])
		return x;
	else
		return padre[x] = Find(padre[x], padre);
}

int Union(int x, int y, vector<int>& padre, vector<int>& rep)
{
	int u = Find(x, padre), v = Find(y, padre);
	if(u != v)
	{
		if(rep[u] > rep[v])
		{
			rep[u] += rep[v];
			padre[v] = u;
			return rep[u];
		}
		rep[v] += rep[u];
		padre[u] = v;
		return rep[v];
	}
	return rep[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while(t--)
	{
		vector<int> padre(100005), rep(100005);
		map<string, int> mapa;
		
		cin >> n;
		cin.ignore();

		for(int i = 0; i <= min(2*n, 100000); i++)
		{
			rep[i] = 1;
			padre[i] = i;
		}

		int index = 0, x, y;

		string a, b;
		
		while(n--)
		{
			cin >> a >> b;
			
			x = mapa[a];
			if(x == 0)
			{
				index++;
				mapa[a] = index;
				x = index;
			}
			
			y = mapa[b];
			if(y == 0)
			{
				index++;
				mapa[b] = index;
				y = index;
			}

			cout << Union(x, y, padre, rep) << "\n";
		}
	}
	
	return 0;
}