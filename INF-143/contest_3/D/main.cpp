#include<bits/stdc++.h>
#define M 1000001

using namespace std;

vector<int> v(M);

void gen()
{
	for(int i = 1; i < M; i++)
		v[i] = sqrt(i);
}

int main()
{
	gen();

	int T, a, b;

	cin >> T;

	while(T--)
	{
		cin >> a >> b;
		if(v[a] % 2 == 0)
			cout << v[b] - v[a] << "\n";
		else
			cout << v[b] - v[a] + 1<< "\n";
	}
	return 0;
}