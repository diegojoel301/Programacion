#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i = 0, value, aux; i < n; i++) 
	{
		cin >> value;
		if(i == 0)
			v[i] = value;
		else
			v[i] = value - aux;
		aux = value;
	}

	for(int i = 0; i < n - 1; i++)
		cout << v[i] << " ";
	cout << v[n - 1];

	return 0;
}