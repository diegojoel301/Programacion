#include<bits/stdc++.h>

using namespace std;

int binpow(int a, int b)
{
	if(b == 0)
		return 1;
	int res = binpow(a, b / 2);
	if(b % 2)
		return res * res * a;
	else
		return res * res;
}

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("input.txt", "r", stdin);

	int d = 20, ans;
	int potencia = binpow(2, d), t, i;
	vector<bool> mapa(potencia, false);
	vector<vector<int>> sol(524289);

	for(int j = 1; j <= 524288; j++)
	{
		ans = 1;
		for(int k = 1; k <= d; k++)
		{
			sol[j].push_back(ans);
			if(not mapa[ans])
			{
				mapa[ans] = true;
				ans = 2 * ans;
			}
			else
			{
				mapa[ans] = false;
				ans = (2 * ans) + 1;
			}
		}
	}
	
	while(true)
	{
		cin >> t;

		if(t == -1)
			break;
		while(t--)
		{
			cin >> d >> i;

			cout << sol[i][d - 1] << "\n";
		}
	}
	
	return 0;
}
