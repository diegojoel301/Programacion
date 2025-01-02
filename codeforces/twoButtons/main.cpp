#include<bits/stdc++.h>

using namespace std;

int n, m, v[200000001];
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	fill(v, v + 200000001, 1e9); // llenar el vector de INF's

	q.push(n);
	v[n] = 0;

	while(q.size())
	{
		int i = q.front();
		q.pop();

		if(i > 0 and v[i] + 1 < v[i - 1])
		{
			v[i - 1] = v[i] + 1;
			q.push(i - 1);
		}

		if(i <= 100000000 and v[i] + 1 < v[i * 2])
		{
			v[i * 2] = v[i] + 1;
			q.push(i * 2);
		}
	}

	cout << v[m];

	return 0;
}