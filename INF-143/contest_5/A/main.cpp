#include<bits/stdc++.h>

using namespace std;

long long int izquierda(int n)
{
	return (n - 1) * (n) / 2;
}

long long int derecha(long long int n, long long int N)
{
	return (N * (N + 1) / 2) - (n * (n + 1) / 2);
}

bool f(long long int n, long long int N)
{
	return izquierda(n) == derecha(n, N);
}

int main()
{
	freopen("input.txt", "r", stdin);

	long long int n;
	
	while(cin >> n)
	{	
		long long int low = 1, high = n, mid;
		
		while(high - low > 1)
		{
			mid = (low + high) / 2;
			cout << "\t" << mid << "\n";
			cout << "\t\t" << izquierda(mid) << " " <<  derecha(mid, n) << "\n";
			if(izquierda(mid) <= derecha(mid, n))
				low = mid;
			else
				high = mid;

		}
		/*
		if(f(low, n))
			cout << low << "\n";
		else
			cout << "NO\n";*/
		cout << low << "\n";
		
	}

	return 0;
}