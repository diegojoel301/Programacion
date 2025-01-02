#include<bits/stdc++.h>
#define N 4294967296

using namespace std;

int f(int x)
{
	int ans = 0, val = x;

	if(x == 0)
		return 1;

	if(x == 1)
		return 3;

	for(int i = x - 1; i >= 1; i--)
	{
		//cout << val << "\n";
		ans = ((ans % N) + (val % N)) % N;
		val = ((val % N) * (i % N)) % N; 
	}

	return ((ans % N) + 1 + (val % N)) % N;
}

int main()
{
	int n;

	cin >> n;

	cout << f(n);

	return 0;
}