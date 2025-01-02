#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--)
	{
		long long int a, b, k;

		cin >> a >> b >> k;

		long long int izq = ceil(k / 2), der = k - ceil(k / 2);

		long long int ans = (a * der) - (b * izq);

		cout << ans << "\n";	
	}
	return 0;
}