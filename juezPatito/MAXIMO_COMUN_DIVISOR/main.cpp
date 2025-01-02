#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void commDiv(int a, int b, vector<int>& v)
{
	int n = gcd(a, b);

	for(int i = 1; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			if(n / i == i)
				v.push_back(i);
			else
			{
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}
}

int main()
{
	int a, b, n, m, q, res;

	cin >> n >> m;
	cin >> q;

	vector<int> v;
	commDiv(n, m, v);
	sort(v.begin(), v.end());

	while(q--)
	{
		cin >> a >> b;
		res = -1;

		for(int i = 0; i < v.size(); i++)
		{
			if(res < v[i] and (a <= v[i] and v[i] <= b))
				res = v[i];
		}

		cout << res << "\n";
	}

	return 0;
}