#include<iostream>
#include <math.h>
#include<iomanip>
#include<cstdio>

using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
	int T;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		int x1, y1, r1, x2, y2, r2;

		cin >> x1 >> y1;
		cin >> r1;

		cin >> x2 >> y2;
		cin >> r2;

		double dcc = distance(x1, y1, x2, y2) - (r1 + r2);

		if(dcc <= 0)
			cout << "Todo OK\n";
		else
			printf("%.2f\n", dcc);
	}
	return 0;
}