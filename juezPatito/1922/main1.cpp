#include<bits/stdc++.h>
const int N = 1e3 + 50;

using namespace std;

int n;

vector<tuple<int, bool, bool, bool>> v;

int dp[N][2][2][2];

int f(int pos, bool s1, bool s2, bool s3)
{
	if(pos == v.size())
	{
		if(s1 and s2 and s3)
			return 0;
		return 1e9;
	}

	int &ans = dp[pos][s1][s2][s3];

	if(ans != -1)
		return ans;

	ans = 1e9;

	ans = min(ans, f(pos + 1, s1 or get<1>(v[pos]), s2 or get<2>(v[pos]), s3 or get<3>(v[pos])) + get<0>(v[pos]));
	ans = min(ans, f(pos + 1, s1, s2, s3));

	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dinero;

	cin >> n;

	memset(dp, -1, sizeof dp);

	string cad;

	for(int j = 0; j < n; j++)
	{
		cin >> dinero >> cad;

		bool s1 = false, s2 = false, s3 = false;

		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] == 'F')
				s1 = true;
			else if(cad[i] == 'W')
				s2 = true;
			else if(cad[i] == 'B')
				s3 = true;
		}

		v.push_back({dinero, s1, s2, s3});

	}

	int res = f(0, 0, 0, 0);

	if(res == 1e9)
		cout << "-1";
	else
		cout << res;

	return 0;
}