#include<bits/stdc++.h>

using namespace std;

bool f(int x)
{
	int cd = 0, s = 0;

	ciclo_1:

		int digito = x % 10;

		if(digito != 2 and digito != 3 and digito != 5 and digito != 7) goto condicion_1;
		{
			cd++;
			s += digito;
		}

		condicion_1: x /= 10;
	if(x > 0) goto ciclo_1;

	if(s % 2 != 0 or cd < 3) goto condicion_2;
		return true;
	condicion_2: return false;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, ans = 0;

	cin >> n;

	ciclo:

		cin >> x;

		if(not f(x)) goto condicion;
			ans++;

		condicion: n--;
	if(n) goto ciclo;

	cout << ans;

	return 0;
}