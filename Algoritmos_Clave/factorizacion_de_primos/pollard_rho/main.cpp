#include<iostream>
#include<math.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if(b == 0)
		return a;
	else
		return gcd(a, a % b);
}

int rho_pollard(int n)
{
	long long int a = 2, b = 2, d, e;
	int i = 1;
	bool band = false;

	while(not band)
	{
		a = (a * a + 1) % n;
		b = (b * b + 1) % n;
		b = (b * b + 1) % n;
		e = abs(a - b);
		d = gcd(e, n);

		cout << "\n\t i = " << i;
		cout << "\n\t a: " << a;
		cout << "\n\t b: " << b;
		cout << "\n\t d = mcd(" << e << ", " << n << "):" << d;

		if(1 < d && d < n)
		{
			band = true;
			return d;
		}
		if(d >= n)
		{
			band = true;
			return -1;
		}

		i++;
	}
	return -1;
}

int main()
{
	int x, n;

	cin >> n;

	x = rho_pollard(n);

	if(x != -1)
	{
		cout << "\n\n\t El Primer Factor es: " << x;
		cout << "\n\t El Segundo Factor es: " << n / x << "\n";
	}
	else
		cout << "\n\tNumero no factorizable....\n";

	return 0;
}
