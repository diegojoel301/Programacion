#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x = 0,
		y = 0, lim = 3, sgn = 1, c = 0, N;

	bool flag = true;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		y = y + sgn;

		if(y == 0)
		{
			y = 1;
			flag = true;
			sgn = 1;
		}

		cout << x + y << " ";
		x += y;

		if(flag)
		{
			c++;

			if(c == lim)
			{
				c = 0;
				sgn = -1;
				flag = false;
				lim++;
			}
		}
		
	}

	return 0;
}