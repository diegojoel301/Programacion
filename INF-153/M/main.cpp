#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, i = 0, val;

	vector<int> v;

	cin >> n >> m;

	ciclo:
	{
		cin >> val;

		v.push_back(val);

		i++;
	}
	if(i < n + m) goto ciclo;

	sort(v.begin(), v.end());

	i = 0;

	ciclo_1:
		cout << v[i] << "\n";
		i++;
	if(i < n + m) goto ciclo_1;

	return 0;
}