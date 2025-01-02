#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;

	cin >> t;

	while(t--)
	{
		bool sw = false;
		long long int x = 1, c, n, a = -1, b = 1, cx = 0, y = 1;

		cin >> n;

		c = a + b;

		string out = "";

		while(n--)
		{
			if(not sw)
			{
				//cout << c << " ";
				out += to_string(c) + " ";
				cx++;

				if(c + 1 == cx)
				{
					a = b;
					b = c;
					c = a + b;
					cx = 0;
					sw = true;
				}
			}
			else
			{
				out += to_string(x) + " ";
				y = y + 2;
				x = x * y * (y - 1);
				sw = false;
			}
		}

		cout << out.substr(0, out.length() - 1) << "\n";
	}

	return 0;
}