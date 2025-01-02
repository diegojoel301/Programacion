#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T, D, I;
	cin >> T;

	while(T--)
	{
		int k = 1;
		cin >> D >> I;

		for(int i = 0; i < D - 1; i++)
		{
			if(I % 2)
			{
				k = 2 * k;
				I = (I + 1) / 2;
			}
			else
			{
				k = 2*k + 1;
				I = I / 2;
			}
		}

		cout << k << "\n";
	}

	return 0;
}