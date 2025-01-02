#include<bits/stdc++.h>

using namespace std;

int f(int n)
{
	int nx = 0;

	ciclo_1:
		nx += (n % 10) * (n % 10);

		n /= 10;

	if(n > 0) goto ciclo_1;

	return nx;
}

int main()
{
	int n;

	cin >> n;

	if(f(f(f(f(f(f(f(f(f(n))))))))) != 1) goto condicion_1;
	{
		cout << "SI\n";
		return 0;
	}

	condicion_1:cout << "NO\n";
	return 0;
}