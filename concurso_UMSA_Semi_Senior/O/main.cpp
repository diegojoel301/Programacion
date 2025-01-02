#include<bits/stdc++.h>

using namespace std;

vector<long long int> v(101);

void gen()
{
	v[0] = 0;
	v[1] = 1;

	for(int i = 2; i <= 100; i++)
		v[i] = v[i - 1] + v[i - 2];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	gen();

	int t;
	long long int n;

	cin >> t;

	while(t--)
	{
		cin >> n;
		if(n != 1)
		{
			int low = 0, high = 100, mid;

			while(high - low > 1)
			{
				mid = (high + low) / 2;

				if(v[mid] <= n)
					low = mid;
				else
					high = mid;
			}
			cout << low << "\n";
		}
		else
			cout << "1\n";
	}

	return 0;
}