#include<bits/stdc++.h>

using namespace std;

int maxSubArraySum(vector<int> v)
{
	int best = 0, sum = 0;

	for(int k = 0; k < v.size(); k++)
	{
		sum = max(v[k], sum + v[k]);
		best = max(best, sum);
	}

	return best;
}

int main()
{
	int n, m;

	while(cin >> n >> m)
	{
		vector<vector<int> > mat(n, vector<int> (m, 0));
		vector<int> v(m, 0);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				v[j] += mat[i][j];
			}
		}

		cout << maxSubArraySum(v) << "\n";
	}
	return 0;
}