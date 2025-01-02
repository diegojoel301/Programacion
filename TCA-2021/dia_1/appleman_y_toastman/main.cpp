#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long int n, s = 0;
vector<long long int> v;

int main()
{
	cin >> n;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
		s += value;
	}

	sort(v.begin(), v.end());

	long long int total = s;

	for(int i = 0; i < n - 1; i++)
	{
		total += s;
		s -= v[i]; 
	}
	cout << total << "\n";

	return 0;
}