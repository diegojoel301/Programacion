#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;

	cin >> n;

	vector<pair<int, int>> v;

	int i = 0, x, y;

	ciclo_1:
		cin >> x >> y;
		v.push_back({x, y});
		i++;
	if(i < n) goto ciclo_1;

	i = 0;

	ciclo_2:
		if(v[i].second > v[i + 1].second) goto condicion_1;
			ans += v[i].first*v[i].second + v[i + 1].first*v[i].second;
			v[i + 1].first = 0;
			v[i + 1].second = v[i].second;
			goto condicion_2;
		
		condicion_1: ans += v[i].first*v[i].second;
		condicion_2: i++;
		/*
		if(v[i].second <= v[i + 1].second)
		{
			ans += v[i].first*v[i].second + v[i + 1].first*v[i].second;
			v[i + 1].first = 0;
			v[i + 1].second = v[i].second;
		}
		else
		{
			ans += v[i].first*v[i].second;
		}
		*/
	if(i < n - 1) goto ciclo_2;

	cout << ans;


	return 0;
}