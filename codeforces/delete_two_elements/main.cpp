#include<bits/stdc++.h>

using namespace std;

long long int sol(vector<long long int> v, long long int n, double k)
{
	unordered_map<double, double> m;

	long long int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(m.find(k - v[i]) != m.end())
			count += m[k - v[i]];
		m[v[i]]++;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, t;
	double sum;

	cin >> t;

	while(t--)
	{
		cin >> n;
		sum = 0;
		vector<long long int> v;

		for(int i = 0, value; i < n; i++)
		{
			cin >> value;
			v.push_back(value);
			sum += value;
		}

		cout << sol(v, v.size(), (2 * sum) / n) << "\n";
	}

	return 0;
}