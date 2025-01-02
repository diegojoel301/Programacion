#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	double p, k;
	int ans;

	while(cin >> n >> p)
	{
		k = exp(log(p) / n);

		ans = round(k);

		cout << ans << "\n";
	}
}