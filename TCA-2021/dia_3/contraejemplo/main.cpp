#include<iostream>

using namespace std;

bool aa = false, bb = false;

int gcd(long long int a, long long int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	long long int l, r;

	cin >> l >> r;

	for(long long int a = l; a <= r; a++)
	{
		aa = false;
		for(long long int b = a; b <= r; b++)
		{
			bb = false;
			for(long long int c = b; c <= r; c++)
			{
				if(a < b and b < c)
				{
					if(gcd(a, b) == 1 and gcd(b, c) == 1)
					{
						if(gcd(a, c) != 1)
						{
							cout << a << " " << b << " " << c << "\n";
							bb = true;
							break;
						}
					}
				}
			}
			if(bb)
			{
				aa = true;
				break;
			}
		}
		if(aa)
			break;
	}

	if(not aa)
		cout << -1 << "\n";

	return 0;
}