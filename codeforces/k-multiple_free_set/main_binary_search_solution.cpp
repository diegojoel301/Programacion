#include<bits/stdc++.h>

using namespace std;

bool busqueda_binaria(vector<int> v, int x)
{
	int n = v.size(), low = 0, high = n - 1;

	while(high - low > 1)
	{
		int mid = (high + low) / 2;

		if(v[mid] <= x)
			low = mid;
		else
			high = mid;
	}
	if(x == v[low])
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, k;

	cin >> n >> k;

	vector<int> v(n), s;

	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++)
	{
		if(i == 0)
			s.push_back(v[i]);
		else
		{
			if(v[i] % k != 0)
				s.push_back(v[i]);
			else if(not busqueda_binaria(s, v[i] / k))
				s.push_back(v[i]);
		}
	}

	if(busqueda_binaria(s, s[s.size() - 1] / 2))
		s.pop_back();

	for(int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	cout << "\n";
	cout << s.size() <<"\n";

	return 0;
}