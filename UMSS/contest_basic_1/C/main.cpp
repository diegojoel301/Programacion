#include<bits/stdc++.h>

using namespace std;

int main()
{
	double x;

	cin >> x;

	if(abs((int)x - x) >= 0.5)
		cout << ceil(x);
	else
		cout << (int)x;

	

	return 0;
}