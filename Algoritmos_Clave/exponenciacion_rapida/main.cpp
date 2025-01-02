#include<bits/stdc++.h>

using namespace std;

int potencia(int b, int e)
{
	if(e == 0)
		return 1;

	if(e % 2 == 0)
		return potencia(b * b, e / 2);
	return potencia(b * b, e / 2) * b;
}

int potencia1(int b, int e)
{
	int u = 1;
	while(e)
	{
		if(e & 1)
			u = u * b;
		e /= 2;
		b = b * b;
	}
	return u;
}

int main()
{

	return 0;
}