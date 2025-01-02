#include<bits/stdc++.h>

using namespace std;

int f(int n)
{
	int s = 0;

	for(int i = 1; i < n; i++)
	{
		if(n % i == 0)
			s += i;
	}
	return s;
}

int main()
{
	int N;

	cin >> N;


	if(N == f(N))
		cout << "SI\n";
	else
		cout << "NO\n";

	return 0;
}