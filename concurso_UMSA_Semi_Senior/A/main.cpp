#include<bits/stdc++.h>

using namespace std;

long double f(long double x)
{
	return (-1 + sqrt((8 * x) + 1)) / 2;
}

long double g(long double x)
{
	return (x * (x + 1)) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	long double N, ans;

	cin >> t;

	while(t--)
	{
		cin >> N;
		ans = f(N);

		if(N == g((long long int)ans))
			cout << "Go On Bob " << to_string((long long int)ans) << "\n";
		else
			cout << "Better Luck Next Time\n";
	}


	return 0;
}