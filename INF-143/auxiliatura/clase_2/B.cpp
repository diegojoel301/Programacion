#include<bits/stdc++.h>
#define M 10000010

using namespace std;

int verificar(int x)
{
	int cnt = 0;
	for(int i = 1; i <= x; i++)
	{
		if(x % i == 0)
			cnt++;
	}
	return cnt == 2;
}

int vis[M];
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		memset(vis, 0, sizeof vis);
		string num;
		cin >> num;

		int sz = num.size();

		for(int i = 0; i < num.size(); ++i)
		{
			int numero = 0;
			for(int j = i; j < min((int)num.size(), i + 5); ++j)
			{
				numero = 10 * numero + (num[j] - '0')
				if(verificar(numero))
					vis[numero] = 1;
			}
		}
	}
	
	int s = 0;
	for(int i = 0; i < M; i++)
		s += vis[i];

	cout << s << "\n";

	return 0;
}