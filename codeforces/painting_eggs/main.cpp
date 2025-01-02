#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, sa = 0, sg = 0, a, g;

	cin >> n;

	string out = "";

	while(n--)
	{
		cin >> a >> g;

		if(abs(sa + a - sg) <= 500)
		{
			sa += a;
			out += "A";
		}
		else
		{
			sg += g;
			out += "G";
		}
	}

	cout << out << "\n";


	return 0;
}