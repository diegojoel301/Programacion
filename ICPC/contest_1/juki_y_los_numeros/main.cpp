#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	char in[100];
	cin >> in;
	vector<int> v;

	for(int i = 0;(48 <= (int)in[i] and (int)in[i] <= 57) or in[i] == '+'; i++)
	{
		if(i % 2 == 0)
			v.push_back((int)in[i] - 48);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size() - 1; i++)
		cout << v[i] << "+";
	cout << v[v.size() - 1] << "\n";
	return 0;
}