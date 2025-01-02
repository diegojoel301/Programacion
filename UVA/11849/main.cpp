#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, c;

	while(true)
	{
		cin >> n >> m;

		if(n == 0 and m == 0)
			break;

		c = 0;
		map<int, int> mapa;
		map<int, int>::iterator itr;

		for(int i = 0, value; i < n + m; i++)
		{
			cin >> value;

			mapa[value]++;
		}

		for(itr = mapa.begin(); itr != mapa.end(); itr++)
		{
			if(itr->second > 1)
				c++;
		}
		cout << c << "\n";
	}

	return 0;
}