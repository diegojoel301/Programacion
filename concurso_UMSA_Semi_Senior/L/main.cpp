#include<bits/stdc++.h>

using namespace std;

bool f(const pair<char, int> a, const pair<char, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string cad;

	while(cin >> cad)
	{
		vector<pair<char, int>> v;
		map<char, int> mapa;

		for(int i = 0; i < cad.size(); i++)
			mapa[cad[i]]++;

		map<char, int>::iterator itr;

		for(itr = mapa.begin(); itr != mapa.end(); itr++)
			v.push_back(make_pair(itr->first, itr->second));

		sort(v.begin(), v.end(), f);

		for(int i = 0; i < v.size(); i++)
			cout << v[i].first << "=" << v[i].second << "\n";
		cout << "\n";

	}

	return 0;
}