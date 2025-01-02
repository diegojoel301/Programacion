#include<bits/stdc++.h>
#define M 1000001

using namespace std;

vector<long long> v(M);

long long sumFacto(int n)
{
	long long s = 0;

	for(int p = 2; p * p <= n; p = (p == 2) ? 3: (p +  2))
	{
		if(n % p) continue;
		s += p;
		do n /= p; while(!(n % p));
	}
	if(n > 1)
		s += n;

	return s;
}

void gen()
{
	for(int i = 0; i < M; i++)
		v[i] = sumFacto(i);
}

int main()
{
	gen();

	int Q, A, B;
	long long s;
	
	cin >> Q;

	while(Q--)
	{
		cin >> A >> B;
		s = 0;

		for(int i = A; i <= B; i++)
			s += v[i];
		cout << s << "\n";
	}

	return 0;
}