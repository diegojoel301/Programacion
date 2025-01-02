#include<bits/stdc++.h>

using namespace std;

long long int SuperSuma(int k, int n)
{
	if(n == 1)
		return 1;
	if(k == 1)
		return (n * (n + 1)) / 2;

	int s = 0;

	for(int i = 1; i <= n; i++)
		s += SuperSuma(k - 1, i);

	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k, n;

	while(cin >> k >> n)
		cout << SuperSuma(k, n)<< "\n";
	return 0;
}
