#include<bits/stdc++.h>

using namespace std;

int n, my = -1;
vector<int> v;

int main()
{
	cin >> n;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;

		v.push_back(value);
	}
	if(n == 1)
		cout << 0 << "\n";
	else
	{
		sort(v.begin(), v.end());

		for(int i = 0; i < n - 1; i++)
		{
			if(v[n - 1] % v[i] > my)
				my = v[n - 1] % v[i];
		}


		cout << my << "\n";
	}

	return 0;
}
