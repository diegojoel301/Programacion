#include<bits/stdc++.h>

using namespace std;

bool sol(vector<int> v)
{
	bool state = false;

	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i + 2; j < v.size(); j++)
		{
			if(v[i] == v[j])
				state = true;
		}
	}

	return state;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, t;

	cin >> t;

	while(t--)
	{
		cin >> n;

		vector<int> v(n);

		for(int i = 0; i < n; i++)
			cin >> v[i];

		if(sol(v))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}