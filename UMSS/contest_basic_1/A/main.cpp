#include<bits/stdc++.h>

using namespace std;

bool check(int x, int d)
{
	int c = 0;
	while(x % 100 == 0)
	{
		c++;
		x /= 100;
	}
	return c == d;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int d, n, c = 0, x = 1;

	cin >> d >> n;

	while(c != n)
	{
		if(check(x, d))
		{
			c++;
		}
		x++;
	}
	cout << x - 1;

	return 0;
}