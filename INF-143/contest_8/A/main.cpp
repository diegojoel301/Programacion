#include<bits/stdc++.h>

using namespace std;

int dp[1010];

int main()
{
	vector<string> v;

	string s;

	while(getline(cin, s))
		v.push_back(s);

	for(int i = v.size() - 1; i >= 0; i--)
	{
		for(int j = i + 1; j < (int)v.size(); ++j)
		{
			if(v[i] <= v[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		dp[i] = max(dp[i], dp[i + 1]);
		dp[i] = max(dp[i], dp[v.size()] + 1);
	}


	cout << dp[0] << "\n***\n";

	int pos = 0;
	while(pos < (int)v.size())
	{
		int res = 0, id = -1;

		for(int i = pos + 1; i < (int)v.size(); ++i)
		{
			if(v[pos] < v[i])
			{
				if(dp[i] + 1 >= res)
				{
					res = dp[i] + 1;
					id = i;
				}
			}
		}

		if(dp[pos + 1] > res)
			pos++;
		else if(dp[v.size()] + 1 > res)
		{
			cout << v[pos] << "\n";	
			pos = v.size();
		}
		else
		{
			cout << v[pos] << "\n";
			pos = id;
		}
	}

	return 0;
}