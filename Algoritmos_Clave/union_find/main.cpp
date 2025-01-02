#include<bits/stdc++.h>

using namespace std;

int padre[11];

void init(int N)
{
	for(int i = 1; i <= N; i++)
		padre[i] = i;
}

int Find(int x)
{
	if(x == padre[x])
		return x;
	else
	{
		return padre[x] = Find(padre[x]);
	}
}

void Union(int x, int y)
{
	int u = Find(x), v = Find(y);
	padre[u] = v;
}

bool mismoConjunto(int x, int y)
{
	return Find(x) == Find(y);
}

int main()
{
	init(10);

	Union(0, 0);
	Union(1, 0);
	Union(2, 2);
	Union(2, 4);
	Union(3, 3);

	set<int, greater<int>> padres;

	for(int i = 0; i < 5; i++)
		padres.insert(Find(i));

	set<int, greater<int>>:: iterator itr;

	for(itr = padres.begin(); itr != padres.end(); itr++)
		cout << *itr << " ";

	cout << "\n";

	for(int i = 0; i < 10; i++)
		cout << padre[i] << " ";
	cout << "\n";

	return 0;
}