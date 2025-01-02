#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, my = 0;
	cin >> n;

	map<int, int> mapa;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;

		mapa[value]++;

	}

	map<int, int>::iterator itr;

	for(itr = mapa.begin(); itr != mapa.end(); itr++)
	{
		if(my < itr->second)
			my = itr->second;
	}

	cout << n - my;

	return 0;
}
