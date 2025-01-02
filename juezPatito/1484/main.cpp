#include<bits/stdc++.h>

using namespace std;

int N, m = 1, sm = 2;
vector<int> p;
bool sw = true;

bool is_prime(int n)
{
	for(int x = 2; x * x <= n; x++)
	{
		if(n % x == 0)
			return false;
	}
	return true;
}


void genP()
{
	int c = 0, n = 2;

	while(c != N)
	{
		if(is_prime(n))
		{
			p.push_back(n);
			c++;
		}
		n++;
	}
}

int main()
{
	cin >> N;
	genP();

	for(int i = 0; i < N; i++, m += sm, sm++)
	{
		if(sw)
		{
			cout << m << "/" << p[i] << "\n";
			sw = false;
		}
		else
		{
			cout << p[i] << "/" << m << "\n";
			sw = true;
		}
	}
	return 0;
}