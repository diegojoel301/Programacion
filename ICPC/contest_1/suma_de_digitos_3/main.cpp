#include<iostream>

using namespace std;

bool isPrime(int n)
{
	if(n == 1)
		return false;	
	for(int i = 2; i * i <= n; i += 1)
		if(n % i == 0)
			return false;
	return true;
}

int cantidadDigitos(long long n)
{
	int s = 0;

	while(n > 0)
	{
		if(isPrime(n % 10))
			s += n % 10;
		n = n / 10;
	}
	return s;
}



int main()
{
	short int T;

	cin >> T;

	for(int i = 0; i < T; i++)
	{
		long long n;
		cin >> n;

		cout << cantidadDigitos(n) << "\n";
	}
	return 0;
}