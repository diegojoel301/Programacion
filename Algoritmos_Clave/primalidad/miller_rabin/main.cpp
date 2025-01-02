#include<bits/stdc++.h>

using namespace std;

//retorna la expoinenciacion modular (x^y) % p
int power(int x, unsigned int y, int p)
{
	int res = 1; //inicializando el resultado
	x %= p; //actualiza el x si este es mayor o igual a p

	while(y > 0)
	{
		// si y es impar, multiplica x con el resultado
		if(y & 1)
			res = (res * x) % p;
		// y debe ser incluso ahora
		y = y >> 1; //y = y / 2
		x = (x * x) % p;
	}
	return res;
}

bool millerTest(int d, int n)
{
	int a = 2 + rand() % (n - 4);

	int x = power(a, d, n);

	if(x == 1 || x == n - 1)
		return true;

	while(d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if(x == 1)
			return false;
		if(x == n - 1)
			return true;
	}

	return false;
}

bool isPrime(int n, int k)
{
	if(n <= 1 || n == 4)
		return false;
	if(n <= 3)
		return true;

	int d = n - 1;

	while(d % 2 == 0)
		d /= 2;

	for(int i = 0; i < k; i++)
	{
		if(not millerTest(d, n))
			return false;	
	}
	return true;
}


int main()
{
	int n, k = 4; //numero de iteraciones
	cin >> n;
	if(isPrime(n, k))
		cout << "SI\n";
	else
		cout << "NO\n";

	return 0;
}