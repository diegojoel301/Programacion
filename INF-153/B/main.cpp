#include<bits/stdc++.h>

using namespace std;

bool prime[100005];

void criba()
{
	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;

	int p = 2;
	ciclo_1:
		if(prime[p] != true) goto condicion_1;
		{
			int i = p * 2;
			ciclo_2:
				prime[i] = false;
				i += p;
			if(i <= 100005) goto ciclo_2;
		}
		condicion_1: p++;
	if(p * p <= 100005) goto ciclo_1;
}

int distancia_izq(int x)
{
	int dis = 0;

	ciclo_3:
		if(not prime[x]) goto condicion_2;
			return dis;
		condicion_2: dis++;
		x--;
	if(x > 0) goto ciclo_3;

	return -1;
}

int distancia_der(int x)
{
	int dis = 0;

	ciclo_4:
		if(not prime[x]) goto condicion_3;
			return dis;
		condicion_3: dis++;
		x++;
	if(x <= 100005) goto ciclo_4;

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	criba();

	int n, x;

	cin >> n;

	n--;

	ciclo_5:
		cin >> x;
		cout << min(distancia_izq(x), distancia_der(x)) << "\n";
	if(n--) goto ciclo_5;

	return 0;
}