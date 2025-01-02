#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	string cad;
	int n, x, y, i, j, t = 1;

	while(cin >> cad)
	{
		cin >> n;
		vector<string> ans;

		while(n--)
		{
			cin >> x >> y;

			i = min(x, y);
			j = max(x, y);

			bool flag = true;

			char aux;

			for(int pos = i; pos <= j and flag; pos++)
			{
				if(pos == i)
					aux = cad[pos];
				else
				{
					if(aux != cad[pos])
						flag = false;
				}
			}

			if(flag)
				ans.push_back("Yes\n");
			else
				ans.push_back("No\n");
		}

		cout << "Case " << t++ << ":\n";

		for(int i = 0; i < ans.size(); i++)
			cout << ans[i];

	}


	return 0;
}