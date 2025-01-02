#include<bits/stdc++.h>

using namespace std;

int primeFactors(int n)
{
	int c = 0;

	for(int p = 2; p * p <= n; p = (p == 2) ? 3: (p +  2))
	{
		if(n % p) continue;
		c++;
		do n /= p; while(!(n % p));
	}
	if(n > 1)
		c++;
	return c;
}

int main()
{
	int x;

	while(true)
	{
		cin >> x;
		if(x == 0)
			break;
		cout << x << " : " << primeFactors(x) << "\n";
	}

	return 0;
}