#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, s = 0;

	cin >> n;

	vector<int> v;
	v.push_back(0);

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	v.push_back(90);

	for(int i = 0; i < n + 1; i++)
	{
		if(abs(v[i] - v[i + 1]) <= 15)
			s += abs(v[i] - v[i + 1]);
		else
		{
			s += 15;
			break;
		}
	}

	cout << s << "\n";

	return 0;
}