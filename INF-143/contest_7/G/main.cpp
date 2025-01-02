#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int d, t, ans, i;

	cin >> t;

	while(t--)
	{
		cin >> d >> i;
		ans = 1;

		for(int j = 0; j < d; j++)
		{
			if(i % 2 == 0)
			{
				i = i / 2;
				ans = (ans * 2) + 1;
			}
			else
			{
				i = (i + 1) / 2;
				ans = ans * 2;
			}
		}

		cout << ans / 2 << "\n";
	}

	return 0;
}