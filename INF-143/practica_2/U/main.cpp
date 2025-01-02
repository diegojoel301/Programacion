#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while(t--)
	{
		cin >> n;

		set<int> s;

		for(int i = 0, val; i < n; i++)
		{
			cin >> val;

			s.insert(val);
		}
		
		set<int>::iterator itr;
		
		itr = s.begin();
		int a = *itr;
		itr++;
		int b = *itr;

		if(a < b)
			cout << b << "\n";
		else
			cout << "NO\n";
			
	}

	return 0;
}