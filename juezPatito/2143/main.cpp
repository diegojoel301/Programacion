#include<bits/stdc++.h>

using namespace std;

int main()
{
	double a, b, c, d, x;

	cin >> a >> b >> c >> d;

	x = (c * c) + ((b + d) * (b + d)) - (a * a);

	if(x >= 0)
	{
		x = sqrt(x);
		cout << setprecision(2) << fixed << x;
	}
	else
	{
		cout << setprecision(2) << fixed << "0.00+" << sqrt(-x) << "j";
	}
	return 0;
}