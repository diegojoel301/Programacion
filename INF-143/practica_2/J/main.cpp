#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x;

	cin >> n >> x;

	vector<int> v(n), vx(n, 1);

	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 1; i < n; i++)
	{
		if(abs(v[i - 1] - v[i]) <= x)
			vx[i] = vx[i - 1] + 1;
	}

	int my = -1;

	for(int i = 0; i < n; i++)
	{
		if(my < vx[i])
			my = vx[i];
	}

	cout << my;

	return 0;
}