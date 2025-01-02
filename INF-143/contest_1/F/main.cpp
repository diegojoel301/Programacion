#include<bits/stdc++.h>

using namespace std;

long long int facto(int n)
{
	vector<long long int> v;

	v.push_back(1);

	for(int i = 1; i <= n; i++)
		v.push_back(v[i - 1] * i);

	return v[n];

}

int main()
{
	/*
	int f, c;

	cin >> f >> c;
	*/

	cout << to_string(facto(100)) << "\n";

	return 0;
}