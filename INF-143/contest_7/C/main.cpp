#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input1.txt", "r", stdin);

	int N, value1, value2, ans, sum, tam;

	while(true)
	{
		cin >> N;

		if(N == 0)
			break;
		priority_queue<int> pq;
		ans = sum = 0;

		while(N--)
		{
			cin >> value1;
			pq.push(-value1);
		}

		if(pq.size() == 1)
			cout << 0 << "\n";
		else
		{
			while(pq.size() > 1)
			{

				value1 = -pq.top();
				pq.pop();
				value2 = -pq.top();
				pq.pop();

				sum = -value1 - value2;
				pq.push(sum);
				ans -= sum;
				cout << ans << " " << value1 << " " << value2 << "\n";
			}
			cout << "\n";
			cout << ans << "\n";
		}
	}

	return 0;
}