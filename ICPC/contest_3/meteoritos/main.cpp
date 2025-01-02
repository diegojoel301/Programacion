#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int n, shoots = 0;

pair<int, int> shield(0, 1);
//<time, life>

int main()
{
	cin >> n;
	pair<int, int> element;

	for(int i = 0, ti, di; i < n; i++)
	{
		cin >> ti >> di;
		element.first = ti;
		element.second = di;
		v.push_back(element);

		//if(ti > time_max)
		//	time_max = ti;

	}

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++)
	{
		shield.second += (v[i].first - shield.first);
		shield.first = v[i].first;

		if(v[i].second > shield.second)
			shoots++;
		else
			shield.second -= v[i].second;
	}

	cout << shoots << "\n";

	return 0;
}
