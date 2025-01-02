#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> GetCombinationsBitwise(vector<int> & vec)
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
	vector<int> vec = {1, 2, 3, 4};

	vector<vector<int>> combinations = GetCombinationsBitwise(vec);

	for(int i = 0; i < combinations.size(); i++)
	{
		for(int j = 0; j < combinations[i].size(); j++)
			cout << combinations[i][j] << " ";
		cout << "\n";
	}

	return 0;
}