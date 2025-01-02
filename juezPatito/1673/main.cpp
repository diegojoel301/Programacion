#include<bits/stdc++.h>

using namespace std;

pair<int, int> sol(vector<int> dino, int power)
{
	int sum = 0, cantidad = 0;
	for(int i = 0; i < dino.size(); i++)
	{
		if(dino[i] <= power)
		{
			sum += dino[i];
			cantidad++;
		}
		else
			return make_pair(sum, cantidad);
	}
	return make_pair(sum, cantidad);
}

int main()
{
	int N, Q, cd, spd;
	cin >> N;
	vector<int> dino;
	pair<int, int> f;

	for(int i = 0, value; i < N; i++)
	{
		cin >> value;
		dino.push_back(value);
	}

	sort(dino.begin(), dino.end());
	cin >> Q;

	for(int i = 0, value; i < Q; i++)
	{
		cin >> value;
		f = sol(dino, value);
		cout << f.second << " " << f.first << "\n";
	}
	return 0;
}