#include<bits/stdc++.h>

using namespace std;

bool f(const pair<char, int> a, const pair<char, int> b)
{
	if(a.second > b.second)
		return true;
	else if(a.second == b.second)
		return a.first < b.first;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	
	map<char, int> mapa;

	string cad;
	cin.ignore();

	vector<pair<char, int>> sol;

	while(n--)
	{
		getline(cin, cad, '\n');
		
		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] != ' ')
				mapa[cad[i]]++;
		}
	}

	map<char, int>::iterator itr;

	for(itr = mapa.begin(); itr != mapa.end(); itr++)
		sol.push_back(make_pair(itr->first, itr->second));

	sort(sol.begin(), sol.end(), f);

	for(int i = 0; i < sol.size(); i++)
		cout << sol[i].first << " " << sol[i].second << "\n";

	return 0;
}