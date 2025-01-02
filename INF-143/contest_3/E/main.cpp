#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	vector<int> v;

	cin >> n >> k;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	if(k < 0)
		rotate(v.begin(), v.begin() - (k % n), v.end());
	else
		rotate(v.begin(), v.begin() + v.size() - (k % n), v.end());

	string out = "";
	for(int i = 0; i < v.size(); i++)
		out += to_string(v[i]) + " ";
	cout << out.substr(0, out.size() - 1);
	return 0;
}