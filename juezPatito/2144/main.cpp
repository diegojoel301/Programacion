#include<bits/stdc++.h>

using namespace std;

int t, n, m;

bool f(int x)
{
	int cur = x / 2 + x / 3 - x / 6; // (cantidad de rectangulos que puedo formar de altura 2) + (cantidad de rectangulos que puedo formar de altura 3) - (interseccion)
	return n + m <= cur and n <= x / 2 and m <= x / 3;
}

int main()
{
	cin >> t;

	while(t--)
	{
		cin >> n >> m;

		int a = -1, b = 1e7, mid;

		while(b - a > 1)
		{
			mid = (a + b) / 2;
			if(f(mid)) // cuantas pilas de bloques puedo formar hasta mid
				b = mid;
			else
				a = mid;
		}
		cout << b << '\n';

	}

	return 0;
}