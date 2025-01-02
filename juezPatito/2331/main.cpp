#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string x, ans;

	cin >> x;

	vector<int> v;

	for(int i = 0; i < x.size(); i++)
		v.push_back(x[i] - 48);

	int elem_front;

	for(int i = v.size() - 1; i >= 0; i--)
	{
		if(v[i] % 2 == 0)
		{
			bool space = false;
			elem_front = v[i];
			v[i] = -1;

			for(int j = i + 1; j < v.size(); j++)
			{
				if(v[j] == -1)
				{
					v[j] = elem_front;
					space = true;
					break;
				}
			}

			if(not space)
				ans += to_string(elem_front);
		}
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] != -1)
			ans += to_string(v[i]);
	}
	
	cout << ans;

	return 0;
}