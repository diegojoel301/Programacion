#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int y, p;

	while(cin >> y >> p)
	{
		vector<int> v(p);

		for(int i = 0; i < p; i++) cin >> v[i];

		int my = -1, X, Y;

		for(int i = 0; i < p; i++)
		{
			int upper = upper_bound(v.begin() + i + 1, v.end(), v[i] + y - 1) - v.begin() - 1;
			
			if(abs(i - upper) > my)
			{
				my = abs(i - upper);
				X = i;
				Y = upper;
			}
			
		}
		cout << my + 1 << " " << v[X] << " " << v[Y] << "\n";
	}

	return 0;
}
