#include<bits/stdc++.h>
using namespace std;

int cantidad(long long n)
{
	int count = 0, res = 1;

	while(not (n % 2))
	{
		n >>= 1;
		count++;
	}

	if(count)
		res = res * (count + 1);

	for(long long i = 3; i <= sqrt(n); i += 2)
	{
		count = 0;
		while(n % i == 0)
		{
			count++;
			n = n / i;
		}
		if(count)
			res = res * (count + 1);
	}

	if(n > 2)
		res = 2 * res;

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	long long int x;
	
	cin >> t;

	while(t--)
	{
		cin >> x;
		if(cantidad(x) % 2 == 0)
			cout << "PAR" << "\n";
		else
			cout << "IMPAR" << "\n";
	}

	return 0;
}