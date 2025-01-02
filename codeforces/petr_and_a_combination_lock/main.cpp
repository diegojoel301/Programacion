#include<bits/stdc++.h>

using namespace std;

int grados(int x)
{
	if(x < 0)
		return (360 + x) % 360;
	else
		return x % 360;
}

vector<int> sol;

void solve(deque<int> v)
{
	if(v.size() == 1)
	{
		sol.push_back(grados(v.front()));
		return;
	}
	else
	{
		int val1, val2;
		val1 = v.front();
		v.pop_front();
		val2 = v.front();
		v.pop_front();

		deque<int> aux;

		while(not v.empty())
		{
			aux.push_front(v.front());
			v.pop_front();
		}
		aux.push_front(grados(val1 - val2));
		solve(aux);
		aux.pop_front();

		aux.push_front(grados(val1 + val2));
		solve(aux);
		aux.pop_front();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	deque<int> v;

	bool flag = false;

	cin >> n;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	solve(v);

	for(auto value : sol)
	{
		if(value == 0)
		{
			flag = true;
			break;
		}
	}
	
	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}