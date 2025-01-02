#include<iostream>

using namespace std;

bool is_prime(int n)
{
	for(int x = 2; x * x <= n; x++)
	{
		if(n % x == 0)
			return false;
	}
	return true;
}

int compsum(int N)
{
	int c = 0;
	if(is_prime(N))
		return -1;
	
	for(int i = 1; i <= N; i++)
	{
		if(N % i == 0 and not is_prime(i))
			c++;
	}

	return c;
}

int main()
{
	int Q, N;

	cin >> Q;

	for(int i = 0; i < Q; i++)
	{
		cin >> N;

		cout << compsum(N) << "\n";

	}
}