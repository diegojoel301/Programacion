#include<bits/stdc++.h>

using namespace std;

bool prime(int n)
{
	if(n <= 1)
		return 0;

	for(int x = 2; x * x <= n; x++)
		if(n % x == 0)
			return 0;
	return 1;
}

int main()
{
	int T;
	cin >> T;
	int L, R, sum;
	for(int i = 0; i < T; i++)
	{
		cin >> L >> R;
		sum = 0;
		for(int j = L; j <= R; j++)
		{
			if(prime(j))
				sum += j;
		}
		cout << sum << "\n";
	}

	return 0;
}