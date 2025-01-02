#include<bits/stdc++.h>

using namespace std;

double distance(int x0, int y0, int x1, int y1)
{
	return sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0)));
}

int main()
{
	double x0, y0, r0, x1, y1, r1, t, distancia;

	cin >> t;

	while(t--)
	{
		cin >> x0 >> y0 >> r0;
		cin >> x1 >> y1 >> r1;

		distancia = distance(x0, y0, x1, y1);

		if(distancia - (r0 + r1) >= 0)
			cout << "False\n";
		else
			cout << "True\n";
	}

	return 0;
}