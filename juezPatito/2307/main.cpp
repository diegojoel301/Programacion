#include<bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
	if(x < 2)
		return false;

	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, pn, x, cp = 0, s = 0, y = 0;

	cin >> n >> pn;

	bool decreciente = true;

	while(n--)
	{
		cin >> x;
		s += x;
		if(is_prime(x))
			cp++;

		if(x >= y)
			y = x;
		else
			decreciente = false;

	}

	if(decreciente and cp == pn and s % 2 != 0)
		cout << "SI";
	else
		cout << "NO";

	return 0;
}