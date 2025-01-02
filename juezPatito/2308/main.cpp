#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	string cad;

	cin >> t;

	while(t--)
	{

		cin >> cad;

		int c1 = 0, c0 = 0;

		bool s1 = 0, s0 = 0, flag = true;

		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] == '1')
			{
				s0 = false;
				s1 = true;
				c0 = 0;
			}
			else
			{
				s0 = true;
				s1 = false;
				c1 = 0;
			}

			if(s1)
				c1++;
			if(s0)
				c0++;

			if(c1 >= 4 or c0 >= 4)
			{
				cout << "SI\n";
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "NO\n";
	
	}

	
	return 0;
}