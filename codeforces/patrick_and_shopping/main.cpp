#include<bits/stdc++.h>

using namespace std;

int main()
{
	int d1, d2, d3;

	cin >> d1 >> d2 >> d3;

	int c1 = d1 + d3 + d2, c2 = 2*d1  + 2*d2, c3 = 2*d2 + 2*d3, c4 = 2*d1 + 2*d3;

	cout << min(min(min(c1, c2), c3), c4);

	return 0;
}