#include<bits/stdc++.h>

using namespace std;

int power(long long x, unsigned int y, int p)
{
	int res = 1; //resultado inicializado

	x = x % p; // actualiza x si este es mas grande o igual que p

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
	long long int x = 13, y = 10000000000, p = 10;

	cout << "La potencia es: " << power(x, y, p) << "\n";

	return 0;
}