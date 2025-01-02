#include<bits/stdc++.h>

using namespace std;

int sd(int n)
{
	if(n > 0)
		return (n % 10) + sd(n / 10);
	else
		return 0;
}

int main()
{
	int n, a, b;
	string out;
	while(cin >> n)
	{
		out = "";
		a = 35, b = -1;

		for(int i = 0; i < n - 1; i++)
		{
			if(i % 2 == 0)
			{
				out += to_string(a) + "  ";
				b = sd(a);
			}
			else
			{
				out += to_string(b) + "  ";
				a = a + b;
			}
		}

		if((n - 1) % 2 == 0)
		{
			out += to_string(a);
			b = sd(a);
		}
		else
		{
			out += to_string(b);
			a = a + b;
		}
		cout << out << "\n";
	}
	return 0;
}