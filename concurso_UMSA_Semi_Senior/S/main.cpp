#include<bits/stdc++.h>

using namespace std;

bool f(const pair<int , string> a, const pair<int , string> b)
{
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
	{
		if(a.second[1] == b.second[1])
			return a.second[2] < b.second[2];
		else
			return a.second[1] > b.second[1];
	}
	return false;
}

int main()
{
	int N, a;

	string b;

	cin >> N;

	vector<pair<int, string>> v;

	while(N--)
	{
		cin >> a >> b;

		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), f);
	for(int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}