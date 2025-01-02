#include<iostream>

using namespace std;

long long int sump(long long int n)
{
	long long int sum = 0;

	for(long long int p = 2; p * p <= n; p = (p == 2) ? 3: (p +  2))
	{
		if(n % p) continue;
		sum += p;
		do n /= p; while(!(n % p));
	}
	if(n > 1)
		sum += n;
	return sum;
}


int main()
{
	long long int A, B, sum;
	short int T;

	cin >> T;

	for(short int j = 0; j < T; j++)
	{
		sum = 0;

		cin >> A >> B;

		for(long long int i = A; i <= B; i++)
			sum += sump(i);

		cout << sum << "\n";

	}
	return 0;
}