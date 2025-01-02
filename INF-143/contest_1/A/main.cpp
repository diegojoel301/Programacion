#include<bits/stdc++.h>

using namespace std;

void subsetsUtil(vector<int>& A, vector<vector<int>>& res, vector<int>& subset, int index)
{
	res.push_back(subset);

	for(int i = index; i < A.size(); i++)
	{
		subset.push_back(A[i]);

		subsetsUtil(A, res, subset, i + 1);

		subset.pop_back();
	}

	return;
}

vector<vector<int>> subsets(vector<int>& A)
{
	vector<int> subset;
	vector<vector<int>> res;

	int index = 0;

	subsetsUtil(A, res, subset, index);

	return res;
}

int main()
{
	int s, n, c;

	while(cin >> s >> n)
	{
		c = 0;

		vector<int> array;

		for(int i = 0, value; i < n; i++)
		{
			cin >> value;

			array.push_back(value);
		}

		vector<vector<int>> res = subsets(array);

		for(int i = 0, sum; i < res.size(); i++)
		{
			sum = 0;
			for(int j = 0; j < res[i].size(); j++)
				sum += res[i][j];

			if(sum == s)
				c++;
		}
		cout << c << "\n";
	}

	return 0;
}