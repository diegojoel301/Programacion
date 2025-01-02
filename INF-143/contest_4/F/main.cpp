#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> pal;
	pal.push_back("");
	pal.push_back("a"); pal.push_back("b");

	for(int i = 0; i < 50000; i++)
	{
		string cad = pal[i];

		pal.push_back("a" + cad + "a"); pal.push_back("b" + cad + "b");
	}

	sort(pal.begin(), pal.end());

	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		cout << pal[n] << "\n";
	}

	return 0;
} 