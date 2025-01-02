#include<bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin >> n;
	string first = "", second = "";

	for(int i = 1; i <= n; i++)
	{
		first += to_string(i % 2);
		second += to_string(not(i % 2));
	}

	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
			cout << first << "\n";
		else
			cout << second << "\n";
	}

	return 0;
}