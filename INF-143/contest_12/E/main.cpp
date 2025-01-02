#include<bits/stdc++.h>

using namespace std;

int padre[26];

void init()
{
	for(int i = 0; i < 26; i++)
		padre[i] = i + 97;
}

int Find(int x)
{
	if(x == padre[x - 97])
		return x;
	else
		return padre[x - 97] = Find(padre[x - 97]);
}

void Union(int x, int y)
{
	int u = Find(x), v = Find(y);
	padre[u - 97] = v;
}

bool mismoConjunto(int x, int y)
{
	return Find(x) == Find(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	init();

	int n;

	cin >> n;

	string cad;

	set<int> letters;

	while(n--)
	{
		cin >> cad;

		int c = cad[0];

		letters.insert(c);

		for(int i = 1; i < cad.size(); i++)
		{
			Union(c, cad[i]);
			c = cad[i];
			letters.insert(cad[i]);
		}
	}

	set<int> ans;

	set<int>::iterator itr;

	for(itr = letters.begin(); itr != letters.end(); itr++)
		ans.insert(Find(*itr));

	cout << ans.size();

	return 0;
}