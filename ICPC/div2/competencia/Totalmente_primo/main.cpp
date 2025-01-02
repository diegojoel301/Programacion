#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int A[N];
int n, k;

bool estado[N];

bool prime[21];

void criba()
{
	memset(prime, true, sizeof(prime));

	for(int p = 2; p * p <= 21; p++)
	{
		if(prime[p] == true)
		{
			for(int i = p * 2; i <= 21; i += p)
				prime[i] = false;
		}
	}
	prime[1] = prime[0] = false;
}

void subconjuntos(int i, int& contador)
{
	if(i == n)
	{
		int cnt = 0, cnt_ones = 0;
		for(int i = 0; i < n; i++)
		{
			if(estado[i])
			{
				cnt_ones++;
				if(prime[A[i]])
					cnt++;
			}
		}

		if(prime[cnt_ones] and cnt >= k)
			contador++;

		return;
	}
	else
	{
		estado[i] = 0;
		subconjuntos(i + 1, contador);
		estado[i] = 1;
		subconjuntos(i + 1, contador);
	}
	

}

int main()
{
	criba();
	int contador = 0;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> A[i];

	subconjuntos(0, contador);

	cout << contador;

	return 0;
}