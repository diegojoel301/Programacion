#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;

	vector<int> v(n);

	for(int i = 0, value, aux; i < n; i++) 
	{
		cin >> value;
		sum += value;
		v[i] = sum;
	}

	if(v[v.size() - 1] % 2 == 0)
		rotate(v.begin(), v.begin() + v.size() - 1, v.end());
	else
		rotate(v.begin(), v.begin() + 1, v.end());

	for(int i = 0; i < n - 1; i++)
		cout << v[i] << " ";
	cout << v[n - 1];

	return 0;
}