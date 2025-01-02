#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int t, n, ca, cb;
	char cad[50];
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> cad;

		bool flag = true;

		for(int i = 0; i < n and flag; i++)
		{
			ca = 0;
			cb = 0;

			if(cad[i] == 'a') ca++;

			if(cad[i] == 'b') cb++;

			for(int j = i + 1; j < n; j++)
			{
				if(cad[j] == 'a') ca++;

				if(cad[j] == 'b') cb++;

				if(ca == cb)
				{
					cout << i + 1 << " " << j + 1 << "\n";
					flag = false;
					break;
				}

			}	
		}

		if(flag)
			cout << "-1 -1\n";
	}

	return 0;
}