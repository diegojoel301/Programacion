#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, state;
	double x;

	cin >> n;

	ciclo:
	{
		cin >> x >> state;

		if(state != 1) goto condicion_1;
		{
			printf("%.2f\n", (x - (x * 0.12)));
			goto condicion;
		}
		condicion_1:
		{
			if(state != 2) goto condicion;
				printf("%.2f\n", (x - (x * 0.17)));
		}
		condicion: n--;
	}
	if(n) goto ciclo;

	return 0;
}