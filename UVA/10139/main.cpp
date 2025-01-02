#include<iostream>

using namespace std;

int n, m, aux;

void factors(int x)
{
	while(x % 2 == 0)
	{
		if(m % 2 == 0)
			m /= 2;
		x /= 2;
	}

	for(int i = 3; i * i <= x; i += 2)
	{
		while(x % i == 0)
		{
			if(m % i == 0)
				m /= i;
			x /= i;
		}
	}

	if(x > 2)
	{
		if(m % x == 0)
			m /= x;
	}
}

int main()
{
	while(cin >> n >> m)
	{
		aux = m;
		for(int i = 1; i <= n; i++)
		{
			factors(i);
			if(m == 1)
				break;
		}
			
		if(m == 1)
			cout << aux << " divides " << n << "!\n";
		else
			cout << aux << " does not divide " << n << "!\n";
	}
	return 0;
}