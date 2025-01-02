#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, value;

	cin >> n;

	vector<vector<int>> adj(n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> value;
			if(value == 1)
				adj[i].push_back(j + 1);
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}


	return 0;
}