#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> aux;
	queue<int> general;

	int n, k, x, val;

	cin >> n >> k;

	for(int i = 1; i <= n; i++)
	{
		cin >> x;

		aux.push_back(x);

		if(i % k == 0)
		{
			val = aux.front();
			aux.pop_front();
			aux.push_back(val);

			while(not aux.empty())
			{
				general.push(aux.front());
				aux.pop_front();
			}
		}
	}

	while(general.size() != 1)
	{
		cout << general.front() << " ";
		general.pop();
	}

	cout << general.front();
	general.pop();

	return 0;
}