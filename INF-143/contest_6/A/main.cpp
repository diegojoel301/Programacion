#include<bits/stdc++.h>

using namespace std;

int main()
{
	int value, cnt_der = 0, cnt_izq = 0;
	vector<int> v, nv;
	map<int, int> mapa;

	while(cin >> value)
	{
		mapa[value]++;
		v.push_back(value);
	}

	vector<int>::iterator ip;

	ip = unique(v.begin(), v.begin() + v.size());

	v.resize(distance(v.begin(), ip));

	for(int i = 0; i < v.size(); i++)
	{
		if(mapa[v[i]] == 1)
			nv.push_back(v[i]);
	}

	for(int i = 0; i < nv.size(); i++)
	{
		if(i % 2 == 0)
			cnt_izq++;
		else
			cnt_der++;
	}

	cout << cnt_izq << " " << cnt_der;

	return 0;
}