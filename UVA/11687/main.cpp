#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	return log10(x) + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	string n;
	while(true)
	{
		cin >> n;

		if(n == "END")
			break;
		else if(n == "1")
		{
			cout << "1\n";
			continue;
		}
		int c = 1, x = n.size();

		while(x != 1)
		{
			x = f(x);
			c++;
		}

		cout << c + 1 << "\n";

	}
	return 0;
}