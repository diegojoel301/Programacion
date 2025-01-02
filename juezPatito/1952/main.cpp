#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, A, B, C;

	while(cin >> n)
	{
		while(n--)
		{
			cin >> A >> B >> C;

			if(A % B == 0 and A % C == 0)
				cout << "0\n";
			else
			{
				int ans = 0;
				for(int i = A; i <= B * C; i++)
				{
					if(((A + i) % B == 0) and ((A + i) % C == 0))
					{
						cout << i << "\n";
						break;
					}
				}
			}

		}
	}

	return 0;
}