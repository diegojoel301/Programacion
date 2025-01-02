#include<bits/stdc++.h>
#define sz(a)	(int)(a).size()

using namespace std;

int main()
{
	string cad; cin >> cad;
	string ans = "";

	for(int i = 0; i < sz(cad); i++)
	{
		if(i == 0)
			ans += cad[i];
		else
		{
			if(cad[i] >= ans[0])
				ans = cad[i] + ans;
			else
				ans = ans + cad[i];
		}
	}

	cout << ans << "\n";

	return 0;
}