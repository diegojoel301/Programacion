#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	cin >> t;

	for(int i = 0; i < t; i++)
	{
		cin >> n;

		for(int j = 0, value; j < n; j++)
			cin >> value;
		cout << to_string((long long)pow(2, n) - 1) << "\n";
	}

	return 0;
}