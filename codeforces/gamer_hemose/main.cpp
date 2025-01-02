#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;
	unsigned long long int H, value;
	cin >> t;

	while(t--)
	{
		priority_queue<unsigned long long int> pq;

		cin >> n >> H;

		for(int i = 0; i < n; i++)
		{
			cin >> value;
			pq.push(value);
		}

		unsigned long long int x, y, ans;
		
		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();

		if(H % (x + y) == 0)
			ans =  2 * (H / (x + y));
		else if(H % (x + y) <= x)
			ans = 2 * ceil(H / (x + y)) + 1;
		else
			ans = 2 * ceil(H / (x + y)) + 2;

		cout << ans << "\n";
	}
		
	return 0;
}