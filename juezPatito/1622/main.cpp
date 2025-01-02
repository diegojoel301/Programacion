#include<bits/stdc++.h>

using namespace std;

void sol(int a, int b, int n)
{
	string out = "";
	out += to_string(a) + "+" + to_string(b) + "+";

	vector<long long int> v(n + 1);

	v[0] = a;
	v[1] = b;

	for(int i = 2; i < n; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		out += to_string(v[i]) + "+";
	}

	cout << out.substr(0, out.size() - 1) << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t, a, b, N;

	cin >> t;

	while(t--)
	{
		cin >> N;
		cin >> a >> b;
		sol(a, b, N);	
	}
	return 0;
}