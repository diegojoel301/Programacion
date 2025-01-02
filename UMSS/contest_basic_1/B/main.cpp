#include<bits/stdc++.h>

using namespace std;

int sum(int n)
{
	if(n > 0)
		return (n % 10) + sum(n / 10);
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	if(N % sum(N) == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}