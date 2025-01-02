#include<bits/stdc++.h>

using namespace std;

vector<int> v(10005, 0);
vector<int> ac(10005, 0);

int A(int x)
{
	if(x > 0)
		return (x % 10) + A(x / 10);
	else
		return 0;
}

void gen()
{
	for(int i = 0; i <= 10004; i++)
		v[i] = A(i);

	for(int i = 1; i <= 10000; i++)
	{
		if(v[i + 1] < v[i])
			ac[i] = 1 + ac[i - 1];
		else
			ac[i] = ac[i - 1];
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	gen();

	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		cout << ac[n] << "\n";
	}

	return 0;
}