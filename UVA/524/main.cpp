#include<bits/stdc++.h>

using namespace std;

int c = 0, n;
int circulo[20];
bool visitados[20];

bool is_prime(int p)
{
	for(int x = 2; x * x <= p; x++)
	{
		if(p % x == 0)
			return false;
	}
	return true;
}

void sol(int m)
{
	if(m == n - 1 and is_prime(circulo[n - 1] + circulo[n]))
	{
		for(int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d" : "%d ", circulo[i]);
		printf("\n");
		return;
	}
	for(int i = 2; i <= n; i++)
	{
		if(not visitados[i] and is_prime(circulo[m] + i))
		{
			visitados[i] = true;
			circulo[m + 1] = i;
			sol(m + 1);
			visitados[i] = false;
		}
	}
}


int main()
{	
	while(cin >> n)
	{
		c++;
		if(c > 1) cout << "\n";
		circulo[0] = circulo[n] = 1;
		printf("Case %d:\n", c);
		
		sol(0);
		
	}

	return 0;
}