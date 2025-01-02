#include<bits/stdc++.h>

using namespace std;

long long int p[91];

void gen()
{
	p[0] = p[1] = p[2] = 1;

	for(int i = 3; i <= 90; i++)
		p[i] = p[i - 2] + p[i - 3];
}

int main()
{
	gen();
	int n;

	while(cin >> n)
		cout << p[n] << "\n";
	return 0;
}