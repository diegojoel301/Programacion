#include<bits/stdc++.h>

using namespace std;

void mostrar(vector<int> v)
{
	for(int i = 0; i < v.size() - 1; i++)
		cout << v[i] << " ";
	cout << v[v.size() - 1]<< "\n";

}

int main()
{
	int n;

	cin >> n;

	for(int i = 0, a; i < n; i++)
	{
		cin >> a;

		vector<int> v;

		for(int j = 0, value; j < a; j++)
		{
			cin >> value;
			v.push_back(value);
		}
		sort(v.begin(), v.end());
		mostrar(v);
	}

	return 0;
}