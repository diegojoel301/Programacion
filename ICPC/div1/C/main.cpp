#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a = 3, b = 5;

	vector<pair<double, double>> v;

	for(double i = 0; i <= 1; i += 0.1)
	{
		cout << (a * i) << " " << (b * (1 - i)) << "\n";
		v.push_back({a * i, b * (1 - i)});
	}

	sort(v.begin(), v.end());

	cout << v[v.size() - 1].first << " " << v[v.size() - 1].second;


	return 0;
}