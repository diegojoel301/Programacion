#include<bits/stdc++.h>

using namespace std;

long long int f(long long int n){
	return (n * (n + 1)) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<long long int, long long int> mapa;

	for (long long int i = 1; i <= 10000; ++i)
		mapa[f(i)] = i;

	long long int t, n;

	cin >> t;

	for (long long int i = 0; i < t; ++i)
	{
		cin >> n;

		if(mapa[n] == 0)
			cout << "No llegas\n";
		else
			cout << "Llegas al cuadro " << mapa[n] << "\n";
	}

	return 0;
}