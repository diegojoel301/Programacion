#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> GetCombinationsBitWise(vector<int>& vec)
{
	int sz = vec.size();

	vector<vector<int>> combinations;

	for(int mask = 0; mask < (1 << sz); mask++)
	{
		vector<int> comb;

		for(int pos = 0; pos < sz; pos++)
		{
			if(mask & (1 << pos))
				comb.push_back(vec[pos]);
		}
		combinations.push_back(comb);
	}

	return combinations;
}

int main()
{
	vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<vector<int>> combinations = GetCombinationsBitWise(vec);
	sort(combinations.begin(), combinations.end());

	int N, s, t;

	cin >> N;

	while(N--)
	{
		cin >> s >> t;
		bool flag = false;
		string sol = "";

		for(int i = 0; i < combinations.size(); i++)
		{
			if(combinations[i].size() == t)
			{
				sol = "";		
				int sum = 0;

				for(int j = 0; j < combinations[i].size(); j++)
				{
					sum += combinations[i][j];
					sol += to_string(combinations[i][j]) + " ";
				}

				if(sum == s)
				{
					flag = true;
					break;
				}

			}
		}

		if(flag)
			cout << sol.substr(0, sol.size() - 1)<< "\n";
		else
			cout << "No solution\n";
	}

	return 0;
}