#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int cnt1, cnt2, x, y, value = 1;

	cin >> cnt1 >> cnt2 >> x >> y;

	map<int, bool> mapc1, mapc2;

	vector<int> c1, c2;

	for(int i = 0; c1.size() != cnt1 or c2.size() != cnt2; i++)
	{
		if(( cnt1 * (x - 1) ) > ( cnt2 * (y - 1) ))
		{
			//parto de c2
			if(value % y != 0 and c2.size() != cnt2 and not mapc1[value])
				c2.push_back(value);
			else
			{
				if(c2.size() == cnt2)
				{
					if(value % x != 0 and c1.size() != cnt1 and not mapc2[value])
						c1.push_back(value);
				}
			}
			
		}
		else
		{
			//parto de c1

		}
		value++;
	}

	return 0;
}