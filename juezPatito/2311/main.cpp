#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double n, x, a, b;

	vector<double> ans, v;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> x;

		v.push_back(x);

	}

	for(int i = 0; i < n - 1; i++)
		ans.push_back((v[i] + v[i + 1]) / 2);

	ans.push_back((v[0] + v[v.size() - 1]) / 2);

	for(int i = 0; i < n - 1; i++)
		printf("%.1f ", ans[i]);
	printf("%.1f\n", ans[ans.size() - 1]);

	return 0;
}