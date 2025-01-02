#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;

	cin >> N;

	string out = "";

	for(int i = 0, value; i < N; i++)
	{
		cin >> value;
		if(value >= 0)
			out += to_string(value) + " ";
		else
			out += "0 ";
	}

	cout << out.substr(0, out.size() - 1);

	return 0;
}