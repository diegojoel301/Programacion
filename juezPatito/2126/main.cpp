#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, g, p, t, e1, e2;

	cin >> n;

	while(n--)
	{
		cin >> g >> p >> t;

		e1 = g * p;
		e2 = g + (p * t);

		if(e1 == e2)
			cout << "0\n";
		else
		{
			if(e1 > e2)
				cout << "2\n";	
			else
				cout << "1\n";
		}
	}

	return 0;
}