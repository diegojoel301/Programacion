#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> v;
	int b, k, exp;
	long long n = 0;
	cin >> b >> k;

	exp = 1;

	for(int i = 0, value; i < k; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	for(int i = k - 1; i >= 0; i--)
	{
		n = (n + v[i] * exp) % 2;
		exp = (exp * b) % 2;
	}


	if(n % 2 == 0)
		cout << "even\n";
	else
		cout << "odd\n";

	return 0;
}