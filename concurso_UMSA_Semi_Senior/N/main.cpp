#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n, m, value, my = -1;
	cin >> k;

	vector< pair<string, int> > v;

	while(k--)
	{
		cin >> n >> m;

		string matrix = "";
		int sum = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m - 1; j++)
			{
				cin >> value;

				if(value)
				{
					matrix += "1 ";
					sum++;
				}
				else
					matrix += "0 ";
			}
			cin >> value;
			if(value)
			{
				matrix += "1\n";
				sum++;
			}
			else
				matrix += "0\n";
		}

		if(sum > my)
			my = sum;

		v.push_back(make_pair(matrix, sum));
	}

	for(int i = 0; i < v.size(); i++)
	{
		if(v[i].second == my)
			cout << v[i].first << "\n";
	}


	return 0;
}