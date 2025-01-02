//https://www.geeksforgeeks.org/check-if-a-number-is-prime-semi-prime-or-composite-for-very-large-numbers/
#include<bits/stdc++.h>

using namespace std;

void prime(long n)
{
	int flag = 0;

	if((n + 1) % 6 != 0 and (n - 1) % 6 != 0)
		cout << "No primo\n";
	else
	{
		double s = sqrt(n);

		if((s * s) == n)
			cout << "Semi-Primo\n";
		else
		{
			long f = (long)s;
			long l = (long)((f * f));

			for(long i = f + 1; i < l; i++)
			{
				long p = i - (long)(sqrt((i * i) - (n)));

				long q = n / p;

				if(p < 2 or q < 2)
					break;

				if((p * q) == n)
				{
					flag = 1;
					break;
				}
				else
					flag = 2;	
			}

			if(flag == 1)
				cout << "Semi-Primo\n";
			else if(flag == 2)
				cout << "Primo\n";
		}
	}
}

int main()
{
	prime(11);
	prime(7894561);
	return 0;
}