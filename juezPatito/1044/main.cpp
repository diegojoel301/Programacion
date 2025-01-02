#include<bits/stdc++.h>

using namespace std;

int h, p, r;

bool a;

string s;

double total, peso;

int main()
{
	
	cin >> h;

	for(int i = 0; i < h; i++)
	{
		cin >> p;
		for(int j = 0; j < p; j++)
		{
			cin >> a >> r;

			for(int k = 0; k < r; k++)
			{
				cin >> s >> peso;

				if(a)
					total += peso;
			}
			if(not a)
				total += 0.5;

		}
	} 

	printf("%.2f\n", total);

	return 0;
}