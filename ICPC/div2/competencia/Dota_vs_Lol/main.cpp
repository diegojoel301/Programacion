#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, L, R, sumD = 0, sumL = 0;

	cin >> N >> M;

	vector<string> v(N + 1);
	vector<pair<int, int>> ac(N + 1); //(dota, lol)
	string value;

	for(int i = 1; i <= N; i++)
	{
		cin >> value;

		v[i] = value;
		if(value == "DOTA")
			sumD++;
		else
			sumL++;
		ac[i].first = sumD;
		ac[i].second = sumL; 
	}
	/*
	for(int i = 1; i <= N;i++)
		cout << v[i] << " ";
	cout << "\n";
	for(int i = 1; i <= N;i++)
		cout << ac[i].first << ", " << ac[i].second << "\n";
	*/

	while(M--)
	{
		int incD = 0, incL = 0, x, y, a, b;
		cin >> L >> R;
		
		x = ac[L].first;
		y = ac[L].second;

		a = ac[R].first;
		b = ac[R].second;

		if(v[L] == "DOTA")
			incD++;
		else
			incL++;

		if(a - x + incD > b - y + incL)
			cout << "DOTA\n";
		else
		{
			if(a - x + incD < b - y + incL)
				cout << "LOL\n";
			else
				cout << "AFK\n";
		}
	
	}

	return 0;
}