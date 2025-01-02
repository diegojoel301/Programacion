#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	int s = 0;
	while(x > 0)
	{
		s += (x % 10);
		x /= 10;
	}
	return s;
}

int main()
{
	cout << f(123);

	return 0;
}