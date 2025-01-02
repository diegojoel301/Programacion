#include<bits/stdc++.h>

using namespace std;

void programa(int a, int b)
{
	string ans = "";

	ciclo:
		ans += to_string(b % 2) + to_string(a % 2);
		a /= 2;
		b /= 2;
	if(a > 0 or b > 0) goto ciclo;

	reverse(ans.begin(), ans.end());

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	bool comodin = false;

	ciclo_2:
		if(not comodin) goto condicion_3;
			programa(a, b);
		condicion_3: comodin = true;
	if(cin >> a >> b) goto ciclo_2;

	return 0;
}