#include <bits/stdc++.h>

using namespace std;

bool verifica(int x)
{
	int c4 = 0, c7 = 0;

	int nro_digitos = log10(x) + 1;

	ciclo_1:
		if(x % 10 != 7) goto condicion_1;
			c7++;
		condicion_1:
		{
			if(x % 10 != 4) goto condicion_2;
				c4++;
		}
		condicion_2: x /= 10;
	if(x > 0) goto ciclo_1;

	return (nro_digitos == c4 + c7) or (nro_digitos == c4) or (nro_digitos == c7);
}

void programa(int n)
{
	if(not (n % 7 == 0 or n % 4 == 0 or verifica(n))) goto condicion_4;
	{
		cout << "YES\n";
		return;
	}

	condicion_4:
	{
		cout << "NO\n";
		return;	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	bool comodin = false;

	ciclo_2:
		if(not comodin) goto condicion_3;
			programa(n);
		condicion_3: comodin = true;
	if(cin >> n) goto ciclo_2;
	
	return 0;
}