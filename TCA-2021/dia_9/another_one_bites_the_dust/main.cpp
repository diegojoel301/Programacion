#include<iostream>

using namespace std;

int main()
{
	long long int a, b, c;

	cin >> a >> b >> c;

	if(not (a == b - 1 or a - 1 == b))
	{
		if(a > b)
			a = b + 1;
		if(a < b)
			b = a + 1;
	}
	cout << a + b + (2 * c) << "\n";

	return 0;
}