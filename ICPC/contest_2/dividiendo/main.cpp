#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

vector<int> ordenar(vector<int> a, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0, tmp; j < n - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				tmp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = tmp;
			}
		}
	}
	return a;
}

int main()
{
	int N, k;

	cin >> N >> k;

	string out = "";

	for(int i = 0; i < N / k; i++)
	{
		vector<int> v;
		for(int j = 0, val; j < k; j++)
		{
			cin >> val;
			v.push_back(val);
		}
		v = ordenar(v, k);

		for(int j = 0; j < k - 1; j++)
			cout << v[j] << " ";
			//out += to_string(v[j]) + " ";
		//out += to_string(v[k - 1]) + "\n";
		cout << v[k - 1] << "\n";
	}
	
	vector<int> v;
	for(int i = 0, val; i < N % k; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	v = ordenar(v, N % k);

	for(int j = 0; j < (N % k) - 1; j++)
		cout << v[j] << " ";
		//out += to_string(v[j]) + " ";
	//out += to_string(v[(N % k) - 1]) + "\n";
	cout << v[(N % k) - 1] << "\n";

	return 0;
}