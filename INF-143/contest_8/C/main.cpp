#include<bits/stdc++.h>

using namespace std;

bool c(const pair<string, int> a, const pair<string, int> b)
{
	return a.first < b.first;
}

char f(char x)
{
	if(x == 'A' or x == 'B' or x == 'C')
		x = '2';
	else if(x == 'D' or x == 'E' or x == 'F')
		x = '3';
	else if(x == 'G' or x == 'H' or x == 'I')
		x = '4';
	else if(x == 'J' or x == 'K' or x == 'L')
		x = '5';
	else if(x == 'M' or x == 'N' or x == 'O')
		x = '6';
	else if(x == 'P' or x == 'R' or x == 'S')
		x = '7';
	else if(x == 'T' or x == 'U' or x == 'V')
		x = '8';
	else if(x == 'W' or x == 'X' or x == 'Y')
		x = '9';

	return x;
}

string t(string cad)
{
	string x;
	for(int i = 0; i < cad.size(); i++)
	{
		if(cad[i] != '-')
			x += f(cad[i]);
	}

	return x.substr(0, 3) + "-" + x.substr(3, 6);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string cad;
	map<string, int> mapa;

	freopen("input.txt", "r", stdin);

	while(cin >> cad)
		mapa[t(cad)]++;

	map<string, int>::iterator itr;

	vector<pair<string, int>> v;

	for(itr = mapa.begin(); itr != mapa.end(); itr++)
	{
		if(itr->second > 1)
			v.push_back(make_pair(itr->first, itr->second));
	}

	if(v.size() > 1)
	{
		sort(v.begin(), v.end(), c);

		for(int i = 0; i < v.size(); i++)
			cout << v[i].first << " " << v[i].second << "\n";
	}
	else
		cout << "Sin duplicados\n";

	return 0;
}