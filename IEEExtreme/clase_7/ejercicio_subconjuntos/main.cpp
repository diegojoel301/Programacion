#include<bits/stdc++.h>

using namespace std;

const int N = 1e5;

int v[N];
bool states[N];

int n, c = 0;

void sol(int pos)
{
	if(n == pos)
	{
		for(int i = 0; i < n; i++)
		{
			if(states[i])
			{
				if(v[i] % 2 != 0)
				{
					c++;
					break;
				}
			}
		}
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

	cout << c << "\n";

	return 0;
}