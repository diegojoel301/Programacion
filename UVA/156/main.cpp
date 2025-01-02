#include<bits/stdc++.h>

using namespace std;

string sortString(string str)
{
	sort(str.begin(), str.end());

	return str;
}

string transform(string a)
{
	string na;
	for(int i = 0; i < a.size(); i++)
	{
		char c = a[i];

		if(islower(c))
			c = c - 32;
		na += c;
	}
	return na;
}

bool comparador(string a, string b)
{
	string na = transform(a), nb = transform(b);

	return sortString(na) == sortString(nb);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<string, int> mapa;
	vector<string> v;

	string cad = "";

	while(true)
	{
		cin >> cad;
		if(cad == "#")
			break;
		mapa[cad] = 0;
		v.push_back(cad);
	}

	for(int i = 0; i < v.size(); i++)
	{
		bool flag = false;
		for(int j = i + 1; j < v.size(); j++)
		{
			if(comparador(v[i], v[j]))
			{
				mapa[v[j]]++;
				flag = true;
			}
		}
		if(flag)
			mapa[v[i]]++;
	}

	map<string, int>::iterator itr;

	for(itr = mapa.begin(); itr != mapa.end(); itr++)
	{
		if(itr->second == 0)
			cout << itr->first << "\n";
	}

	return 0;
}