#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N = 100000000, c = 0;

	for(int y = 0; y <= N; y++)
	{
		for(int x = 0; x <= y; x++)
		{
			if((x ^ y) == x + y)
				c++;
		}
	}

	cout << c << "\n";

	return 0;
}