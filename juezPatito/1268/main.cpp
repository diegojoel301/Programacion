#include<bits/stdc++.h>

using namespace std;

double v(double x, double y)
{
	return (y - (2 * x)) / 2;
}

double g(double x, double y)
{
	return x - v(x, y);
}

int main()
{
	double x = -1, y = -1;

	while(cin >> x >> y)
	{
		if(x == 0 and y == 0) break;

		if((g(x, y) == floor(g(x, y)) and v(x, y) == floor(v(x, y))) and (g(x, y) >= 0 and v(x, y) >= 0))
			cout << g(x, y) << " " << v(x, y) << "\n";
		else
			cout << "-1\n";
		

	}
	return 0;
}