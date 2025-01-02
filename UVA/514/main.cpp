#include<bits/stdc++.h>

using namespace std;

bool verifica(queue<int> q)
{
	int n = 1, N = q.size();
	stack<int> s;

	while(N != n)
	{
		if(q.empty())
			return false;
		if(q.front() == n)
			q.pop();
		else
		{
			if(not s.empty())
			{
				if(s.top() != n)
					return false;
			}
			else
			{
				while(not q.empty())
				{
					int elem = q.front();
					q.pop();
					if(elem == n)
						break;
					s.push(elem);
				}

			}
		}
		n++;
	}
	return true;
}

int main()
{
	int N = -1, value;
	bool flag;
	while(N != 0)
	{
		cin >> N;

		if(N == 0)
			break;

		flag = true;

		while(flag)
		{
			queue<int> v;

			cin >> value;
			if(value == 0)
				break;
			v.push(value);
			for(int i = 0; i < N - 1; i++)
			{
				cin >> value;
				v.push(value);
			}

			if(verifica(v))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << "\n";
	}
}
