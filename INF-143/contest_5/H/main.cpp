#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, s;
	while(cin >> n)
	{
		map<int, int> mapa;
		s = 0;
		for(int i = 0, value; i < n; i++)
		{
			cin >> value;

			mapa[value] += 1;
		}

		map<int, int>::iterator itr;

		for(itr = mapa.begin(); itr != mapa.end(); ++itr)
		{
			if(itr->second % 2 != 0)
				s += (itr->second - 1) / 2;
			else
				s += itr->second / 2;
		}

		cout << s << "\n";
	}

	return 0;
}