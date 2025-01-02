#include<bits/stdc++.h>

using namespace std;

void primeFactors(int n)
{
	while(n % 2 == 0)
	{
		cout << 2 << " ";
		n /= 2;
	}

	for(int i = 3; i * i <= n; i = i + 2)
	{
		while(n % i == 0)
		{
			cout << i << " ";
			n = n/i;
		}
	}

	if(n > 2)
		cout << n << " ";
}

void factorize(long long n) // para numeros largos
{
	int count = 0;

	while(not (n % 2))
	{
		n >>= 1;
		count++;
	}

	if(count)
		cout << 2 << " " << count << "\n";

	for(long long i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while(n % i == 0)
		{
			count++;
			n = n / i;
		}
		if(count)
			cout << i << " " << count << "\n";
	}

	if(n > 2)
		cout << n << " " << 1 << "\n";
}

void primeFactors1(int n) //este sirve para primos sin repeticiones
{
	for(int p = 2; p * p <= n; p = (p == 2) ? 3: (p +  2))
	{
		if(n % p) continue;
		cout << p << " ";
		do n /= p; while(!(n % p));
	}
	if(n > 1)
		cout << n << " ";
}

int cantidad(long long n) //cantidad de divisores
{
	int count = 0, res = 1;

	while(not (n % 2))
	{
		n >>= 1;
		count++;
	}

	if(count)
		res = res * (count + 1);

	for(long long i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while(n % i == 0)
		{
			count++;
			n = n / i;
		}
		if(count)
			res = res * (count + 1);
	}

	if(n > 2)
		res = 2 * res;

	return res;
}

int main()
{
	long long int n;
	while(cin >> n)
	{
		factorize(n); // 1
		cout << "\n";
	}
	return 0;
}