#include<iostream>

using namespace std;

int f(int n)
{
	if(n > 0)
		return (n % 10) + f(n / 10);
	else
		return 0;
}

void g(int n, int aux)
{
	if(n != aux)
		return g(f(n), n);
	else
		cout << n << "\n";
}

int main()
{
	int aux = -1, n = -1;

	while(n != 0)
	{
		cin >> n;
		if(n == 0)
			break;
		
		g(n, -1);
	}
	return 0;
}