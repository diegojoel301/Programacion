#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if(v.size() != 1)
		cout << v[1] << "\n";
	else
		cout << "NO\n";
	return 0;
}