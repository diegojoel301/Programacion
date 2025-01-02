#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, a;

	cin >> n;

	while(n--)
	{
		cin >> a;
		vector<int> v(a);

		for(int i = 0;i < a; i++)
			cin >> v[i];
		sort(v.begin(), v.end());

		for(int i = 0; i < a - 1; i++)
			cout << v[i] << " ";
		cout << v[a - 1] << "\n";

	}

	return 0;
}