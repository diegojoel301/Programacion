#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a;

	bool comodin = false;

	ciclo1:

		if(comodin == true)
		{
			int ans = 0, exp = 1;
			
			ciclo:

				ans += exp * (a % 2);
				exp *= 10;
				a /= 2;
			if(a > 0) goto ciclo;
			
			cout << ans << "\n";
		}
		comodin = true;
	if(cin >> a) goto ciclo1;

	return 0;
}