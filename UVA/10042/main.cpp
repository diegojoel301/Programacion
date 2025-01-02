#include<bits/stdc++.h>

using namespace std;

bool verificaPrimo(int n)
{
	if(n == 1)
		return false;
	for(int x = 2; x * x <= n; x++)
	{
		if(n % x == 0)
			return false;
	}
	return true;
}

int sumaDigitos(int n)
{
	if(n > 0)
		return (n % 10) + sumaDigitos(n / 10);
	else
		return 0;
}

int sumPrime(int n)
{
	int s = 0;
	while(n % 2 == 0)
	{
		s += 2;
		n /= 2; 
	}

	for(int i = 3; i * i <= n; i++)
	{
		while(n % i == 0)
		{
			s += sumaDigitos(i);
			n /= i;
		}
	}

	if(n > 2)
		s += sumaDigitos(n);
	return s;
}

int main()
{
	
	int t;
	cin >> t;

	for(int i = 0, n; i < t; i++)
	{
		cin >> n;
		n++;
		while(sumPrime(n) != sumaDigitos(n) or verificaPrimo(n))
			n++;
		cout << n << "\n";

	}
	return 0;
}