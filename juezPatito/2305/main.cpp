#include<bits/stdc++.h>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	string x, y;

	cin >> n;

	cin >> x;
	cin >> y;

	int ans = 0;

	for(int i = 0; i < x.size(); i++)
	{
		int a = x[i] - 48;
		int b = y[i] - 48;
		
		int ans_1 = abs(a - b);
		int ans_2;

		if(a > b)
			ans_2 = b + abs(9 - a) + 1;
		else
			ans_2 = a + abs(9 - b) + 1;



		//cout << a << " " << b << "->";

		if(ans_1 > ans_2)
		{
			//cout << ans_2 << "\n";
			ans += ans_2;
		}
		else
		{
			//cout << ans_1 << "\n";
			ans += ans_1;
		}

		//cout << ans_1 << " " << ans_2 << "\n";

	}

	cout << ans;

	return 0;
}