#include<bits/stdc++.h>

using namespace std;

bool primeFactors(int n)
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

	if(c == 2)
		return true;
	return false;
}

int main()
{
	int n, cp = 0;

	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		if(primeFactors(i))
			cp++;
	}

	cout << cp << "\n";

	return 0;
}