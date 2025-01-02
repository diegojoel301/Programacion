#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	vector<int> v(n), s;
	map<int, bool> mapa;

	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			s.push_back(v[i]);
			mapa[v[i]] = true;
		}
		else
		{
			if(v[i] % k != 0)
			{
				s.push_back(v[i]);
				mapa[v[i]] = true;
			}	
			else if(not mapa[v[i] / k])
			{
				s.push_back(v[i]);
				mapa[v[i]] = true;
			}
		}
	}

	cout << s.size() <<"\n";

	return 0;
}