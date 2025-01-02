#include<bits/stdc++.h>

using namespace std;

int generado[10010];

int f(int x)
{
	int sum = 0;
	
	while(x > 0)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main()
{
	int a, b;

	for(int i = 1; f(i) < 10010; ++i)
	{
		int gen = f(i);
		if(gen <= 10000)
			generado[gen] = 1;
	}

	for(int i = 1; i < 10010; ++i)
		generado[i] += generado[i - 1];
	
	while(cin >> a >> b) //lectura
	{
		int res = generado[b];
		if(a > 0)
			res -= generado[a - 1];
		
		cout << (b - a + 1) + res << "\n";
	}
	return 0;
}
