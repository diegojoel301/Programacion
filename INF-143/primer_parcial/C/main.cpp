#include<bits/stdc++.h>

using namespace std;

bool verifica(int n)
{
	if(n <= 1)
		return false;
	if(n == 2)
		return true;

	for(int i = 3; i * i <= n; i += 2)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}

vector<long long int> v = {0, 1, 1};

long long int fibo(long long int n, long long int a, long long int b)
{
	v.push_back(b);

	if(n == 0)
		return b;
	return fibo(n - 1, b, a + b);
}

int main()
{
	fibo(997, 1, 2);

	cout << v[300] << "\n";
	return 0;
}