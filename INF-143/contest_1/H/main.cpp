#include<bits/stdc++.h>

using namespace std;

double facto(double n)
{
	if(n == 0)
		return 1;
	else
		return n * facto(n - 1);
}

double sumatoria(double n, int k)
{
	if(k != n)
		return (pow(-1, k) / facto(k)) + sumatoria(n, k + 1);
	else
		return 0;
}

long long int subfacto(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;
	return (n - 1) * (subfacto(n - 1) + subfacto(n - 2));
}

int main()
{
	int n;
	int t;

	cin >> t;

	while(t--)
	{
		cin >> n;
		cout << to_string(fmod(subfacto(n), 100000001)) << "\n";
	}

	return 0;
}