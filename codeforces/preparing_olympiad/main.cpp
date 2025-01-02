#include<bits/stdc++.h>

using namespace std;

const int N = 20;
int n, l, r, x, ans = 0, value;

bool states[N];

long long int f(vector<int> v)
{
	long long int sum = 0;

	for(int i = 0; i < v.size(); i++)
		sum += v[i];
	return sum;
}

bool verifica_sesgo(vector<int> v)
{
	int my = -1, mn = 1e7;

	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] > my)
			my = v[i];
		if(v[i] < mn)
			mn = v[i];
	}

	return abs(my - mn) >= x;
}

void comb(int pos, vector<int> v)
{
	if(pos == n)
	{
		vector<int> vv;

		for(int i = 0; i < v.size(); i++)
		{
			if(states[i])
				vv.push_back(v[i]);
		}

		long long int suma = f(vv);
		if((l <= suma and suma <= r) and verifica_sesgo(vv) and vv.size() >= 2)
			ans++;
	}
	else
	{
		states[pos] = true;
		comb(pos + 1, v);
		states[pos] = false;
		comb(pos + 1, v);
	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(states, false, sizeof states);
	vector<int> v;

	cin >> n >> l >> r >> x;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	comb(0, v);

	cout << ans;
	
	return 0;
}