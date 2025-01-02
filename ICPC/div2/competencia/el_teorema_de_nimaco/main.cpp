#include<bits/stdc++.h>
#define M 1000000

using namespace std;

vector<int> imp(M), pos(M);

void gen()
{
	for(int i = 1, sum = 1; i < M; i++)
	{
		imp[i] = sum;
		sum += 2;
	}
	int x = 1, sum = 1;
	for(int i = 1; i < M; i++)
	{
		pos[i] = x;
		x += sum;
		sum++;
	}
}

int main()
{
	gen();

	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		int ini = pos[n];
		string out = "";
		
		for(int i = 0; i < n; i++)
		{
			out += to_string(imp[ini]) + "+";
			ini++;
		}
		cout << out.substr(0, out.size() - 1) << "\n";
		
	}
}