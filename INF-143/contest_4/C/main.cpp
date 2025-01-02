#include<bits/stdc++.h>

using namespace std;

int S(vector<int> a, int x)
{
	for(int i = 0; i < a.size(); i++)
		if(x == a[i])
			return i;
	return -1;
}

int main()
{
	int N, c;

	while(cin >> N)
	{
		c = 0;
		vector<int> a(N), b(N);

		for(int i = 0; i < N; i++) cin >> a[i];
		for(int i = 0; i < N; i++) cin >> b[i];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for(int i = 0; i < N; i++)
		{
			int pos = S(a, b[i]);
			if(pos != -1)
			{
				a[pos] = -1;
				c++;
			}
		}
		

		cout << N - c << "\n";

	}

	return 0;
}