#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, c = 0;

	int x0, y0;
	int x1, y1;
	int x2, y2;

	char val;
	
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> val;

			if(val == '*')
			{
				if(c == 0)
				{
					x0 = i;
					y0 = j;
				}
				else if(c == 1)
				{
					x1 = i;
					y1 = j;
				}
				else if(c == 2)
				{
					x2 = i;
					y2 = j;
				}
				c++;
			}
		}
	}
	

	if(x0 == x1 and y0 == y2)
		cout << x2 << " " << y1;
	else if(x0 == x2 and y0 == y1)
		cout << x1 << " " << y2;
	else if(x2 == x1 and y2 == y0)
		cout << x0 << " " << y1;
	else if(x2 == x0 and y2 == y1)
		cout << x1 << " " << y0;
	else if(x1 == x2 and y1 == y0)
		cout << x0 << " " << y2;
	else if(x1 == x0 and y1 == y2)
		cout << x2 << " " << y0;
	else if(x0 == x1 and y0 == y2)
		cout << x2 << " " << y1;
	else if(x0 == x2 and y0 == y1)
		cout << x1 << " " << y2;
	else if(x2 == x1 and y2 == y0)
		cout << x0 << " " << y1;
	else if(x2 == x0 and y2 == y1)
		cout << x1 << " " << y0;
	else if(x1 == x2 and y1 == y0)
		cout << x0 << " " << y2;
	else if(x1 == x0 and y1 == y2)
		cout << x2 << " " << y0;


	return 0;
}