#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;

	cin >> n;

	if(n == 0) goto condicion_1;
	{
		double x = 1, ans = 0;

		n--;

		ciclo:
			ans += 1 / x;
			x++;
		if(n--) goto ciclo;

		printf("%.4f", ans);

		return 0;
	}

	condicion_1:

	cout << "0.0000";

	return 0;
}