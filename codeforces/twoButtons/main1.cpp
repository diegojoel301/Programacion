#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, w = 0;

	cin >> n >> m;

	while(n != m)
	{
		if(m > n)
		{
			if(m % 2 == 0)
			{
				m /= 2;
				w++;
			}
			else
			{
				m++;
				w++;
			}
			
		}
		else if(n > m)
		{
			m++;
			w++;
		}
	}

	cout << w;

	return 0;
}