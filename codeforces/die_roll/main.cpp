#include<bits/stdc++.h>

using namespace std;

int main()
{
	int ct = 6, cf, y, w;

	cin >> y >> w;

	if(y == w and y == 1)
	{
		cf = ct = 1;
		cout << "1/1";
	}
	else
	{
		cf = 7 - max(y, w);

		if(cf == 1)
			cout << "1/6";
		else if(cf == 2)
			cout << "1/3";
		else if(cf == 3)
			cout << "1/2";
		else if(cf == 4)
			cout << "2/3";
		else if(cf == 5)
			cout << "5/6";
		else if(cf == 6)
			cout << "1/6";
		
	}
		

	return 0;
}