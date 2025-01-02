//Exponenciacion binaria
#include<bits/stdc++.h>

using namespace std;

const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF = 1e100;
const double EPS = 1e-9;
const double PI = acos(-1);

int expobina(int b, int e, int m)
{
	for(i = 0; i < 30; i++)
	{
		if(e & (1 << i))
			res *=b, res %= m;
		b *= b;
		b %= m;
	}
}

int main()
{
	sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	return 0;
}
