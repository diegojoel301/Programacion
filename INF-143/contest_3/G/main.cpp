#include <bits/stdc++.h>
#define M 100001

using namespace std;

vector<long long int> v;

void gen()
{
	long long int x = 192;
	for(int i = 0; i < M; i++)
	{
		v.push_back(x);
		x += 250;
	}
}

int main()
{
	gen();

	int T, n;
	cin >> T;
	
	while(T--)
	{
		cin >> n;
		cout << v[n - 1] << "\n";	
	}
	return 0;
}