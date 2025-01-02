#include <bits/stdc++.h>
#define M 100001
using namespace std;

vector<int> v(M);

void gen()
{
	for(int i = 1; i < M; i++)
		v[i] = sqrt(i);
}

int main()
{
	gen();

	int T, n;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> n;
		cout << v[n] << " " << n - v[n] << "\n";
	}

	return 0;
}