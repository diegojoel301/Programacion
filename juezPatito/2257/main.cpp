#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x, n;

	cin >> x >> n;

	for(int i = x; i <= x * n; i += x) cout << i << " ";

	return 0;
}