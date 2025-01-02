#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	vector<int> v;

	while(cin >> n)
	{
		v.push_back(n);
		sort(v.begin(), v.end());
		if(v.size() % 2 != 0)
			cout << v[(v.size() / 2)] << "\n";
		else
		{
			cout << (v[(v.size() / 2)] + v[(v.size() / 2) - 1]) / 2 << "\n";
		}
	}

	return 0;
}