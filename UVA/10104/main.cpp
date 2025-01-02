#include<bits/stdc++.h>

using namespace std;

tuple<int, int, int> gcd(int a, int b)
{
	if(b == 0)
		return {1, 0, a};
	else
	{
		int x, y, g;

		tie(x, y, g) = gcd(b, a % b);
		return {y, x - (a / b) * y, g};
	}
}

int main()
{
	int a, b;

	while(cin >> a >> b)
	{
		tuple<int, int, int> mcd = gcd(a, b);
		cout << get<0>(mcd) << " " << get<1>(mcd) << " "<< get<2>(mcd)<< "\n";
	}
	return 0;
}