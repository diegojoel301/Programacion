#include<bits/stdc++.h>

using namespace std;

int power(long long x, unsigned int y, int p)
{
	int res = 1;

	x = x % p;

	if(x == 0)
		return 0;

	while(y > 0)
	{
		if(y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}

	return res;

}

int main()
{
	long long int B, p = 10;
	
	vector<long long int> v(6);

	cin >> B;

	for(int i = 0; i < 6; i++)
		cin >> v[i];

	int res = power(B, v[0], p);

	for(int i = 1; i < 6; i++)
		res = power(res, v[i], p);

	cout << res << "\n";

	return 0;
}