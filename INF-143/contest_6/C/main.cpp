#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, mn, T;
	bool flag;
	cin >> T;

	while(T--)
	{
		mn = 999999999;
		flag = false;
		cin >> n >> m;

		map<int, int> mapa, mapa1;

		map<int, int>::iterator itr;

		for(int i = 0, value; i < n; i++)
		{
			cin >> value;
			mapa[value]++;
		}

		for(int i = 0, value; i < m; i++)
		{
			cin >> value;
			mapa1[value]++;
		}

		for(itr = mapa.begin(); itr != mapa.end(); itr++)
		{
			if(mapa1[itr->first])
			{
				flag = true;
				if(mn > itr->first)
					mn = itr->first;	
			}
		}
		if(flag)
			cout << mn << "\n";
		else
			cout << "-1\n";
	}

	return 0;
}