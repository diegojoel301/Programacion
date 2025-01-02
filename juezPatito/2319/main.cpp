#include<bits/stdc++.h>

using namespace std;

bool verifica(float n)
{
	return ceil(n) == floor(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;

	float x, val;

	cin >> n;

	while(n--)
	{
		cin >> t;

		x = 1;

		while(t--)
		{
			cin >> val;
			x = x * sqrt(val);
		}
		/*
		if(verifica(x))
			cout << "EL producto es numero cuadrado\n";
		else
			cout << "El producto no es numero cuadrado\n";
		*/
		cout << to_string(ceil(x)) << " " << to_string(floor(x)) << "\n";
	}
	return 0;
}