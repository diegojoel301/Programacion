#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

int v[MAX];

int primeFactors(int n)
{
	int s = 0;

	for(int p = 2; p * p <= n; p = (p == 2) ? 3: (p +  2))
	{
		if(n % p) continue;
		s += p;
		do n /= p; while(!(n % p));
	}
	if(n > 1)
		s += n;
	return s;
}

void gen()
{
	for(int i = 2; i <= 1000000; i++)
		v[i] = primeFactors(i);
}

int main()
{
	gen();

	int T, Y;
	cin >> T;

	while(T--)
	{
		cin >> Y;
		cout << v[Y] << "\n";
	}
}