#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

int v[N];
bool states[N];

int n;
set<int> s;

void sol(int pos)
{
	if(n == pos)
	{
		int suma = 0;
		for(int i = 0; i < n; i++)
		{
			if(states[i])
				suma += v[i];
		}
		if(suma > 0)
			s.insert(suma);
		return;
	}
	else
	{
		states[pos] = false;
		sol(pos + 1);
		states[pos] = true;
		sol(pos + 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	memset(states, N, sizeof states);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> v[i];

	sol(0);

	cout << s.size() << "\n";

	return 0;
}