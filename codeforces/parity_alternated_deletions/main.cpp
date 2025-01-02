#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<long long int> pqi, pqp;

	queue<long long int> qp, qi;

	int n, value;
	long long int ans = 0;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> value;

		if(value % 2 == 0)
			pqp.push(value);
		else
			pqi.push(value);
	}

	while(not pqp.empty())
	{
		qp.push(pqp.top());
		pqp.pop();
	}

	while(not pqi.empty())
	{
		qi.push(pqi.top());
		pqi.pop();
	}

	bool flag = qp.size() > qi.size();
	
	while(qp.size() != 0 and qi.size() != 0)
	{
		if(flag)
		{
			flag = not flag;
			qp.pop();
		}
		else
		{
			flag = not flag;
			qi.pop();
		}
	}

	if(flag)
	{
		flag = not flag;
		if(qp.size() != 0)
			qp.pop();
	}
	else
	{
		flag = not flag;
		if(qi.size() != 0)
			qi.pop();
	}

	int tam1 = qp.size(), tam2 = qi.size();

	for(int i = 0; i < tam1; i++)
	{
		ans += qp.front();
		qp.pop();
	}
	cout << "\n";

	for(int i = 0; i < tam2; i++)
	{
		ans += qi.front();
		qi.pop();
	}
	cout << ans;

	return 0;
}