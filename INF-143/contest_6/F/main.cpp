#include<bits/stdc++.h>
#define M 1000

using namespace std;

bool prime[M + 1];

void criba()
{
	for(int p = 2; p * p <= M; p++)
	{
		if(prime[p])
		{
			for(int i = p * 2; i <= M; i += p)
				prime[i] = false;
		}
	}

}

int main()
{
	memset(prime, true, sizeof(prime));
	criba();

	

	return 0;
}