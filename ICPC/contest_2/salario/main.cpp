#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for(int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		if(b == 1)
			printf("%.2f\n", a - (a * 0.12));
		else
			printf("%.2f\n", a - (a * 0.17));
	}
	return 0;
}