#include<bits/stdc++.h>

using namespace std;

int padre[100005];

void init(int n)
{
	for(int i = 1; i <= n; i++)
		padre[i] = i;
}

int Find(int x)
{
	if(x == padre[x])
		return x;
	else
		return padre[x] = Find(padre[x]);
}

int Find1(int x)
{
	if(x == padre[x])
		return x;
	else
		return padre[x] = Find1(padre[x]);
}

int Union(int x, int y)
{
	int u = Find(x), v = Find(y);

	if(u != v)
	{
		padre[u] = v;
		return 1;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, C, ans, x, y;
	bool state;

	cin >> N >> C;

	ans = N;

	init(N);

	while(C--)
	{
		cin >> x >> y >> state;

		if(state)
			ans -= Union(x, y);
		cout << ans << "\n";

	}
	
	return 0;
}