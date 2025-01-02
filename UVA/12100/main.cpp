#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, m, minutes, t;

	cin >> t;

	while(t--)
	{
		cin >> n >> m;
		minutes = 0;
		queue<pair<int, bool>> q;

		for(int i = 0, value; i < n; i++)
		{
			cin >> value;
			q.push(make_pair(value, i == m));
		}
		

		for(int i = 0, size; i < n * n; i++)
		{
			pair<int, bool> elem = q.front(), elem1;
			q.pop();

			bool state = true;

			size = q.size();

			while(size--)
			{
				elem1 = q.front();

				if(elem1.first > elem.first)
					state = false;
				q.pop();
				q.push(elem1);
			}

			if(not state)
				q.push(elem);
			else
			{
				if(elem.second)
					break;
				else
					minutes++;
			}

		}

		cout << minutes + 1 << "\n";
	}

	return 0;
}