#include<bits/stdc++.h>

using namespace std;

vector<bool> v(100000);

int sd(int n)
{
	if(n > 0)
		return (n % 10) + sd(n / 10);
	else
		return 0;
}

int d(int n)
{
	return n + sd(n);
}

bool verifica(int n)
{
	for(int i = n - 1; i >= 1; i--)
	{
		if(d(i) == n)
			return true;
	}
	return false;
}

void gen()
{
	for(int i = 0; i <= 10000; i++)
	{
		if(verifica(i))
			v[i] = true;
		else
			v[i] = false;
	}
}

int main()
{
	int a, b, c;
	gen();
	while(cin >> a >> b)
	{
		c = 0;
		for(int i = a; i <= b; i++)
		{
			if(not v[i])
				c++;
		}
		cout << c << "\n";
	}
	return 0;
}
