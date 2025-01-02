#include<bits/stdc++.h>

using namespace std;

int f(vector<int> v, int x)
{
	int s = 0;

	for(int i = 0; i < v.size(); i++) s += x / v[i];

	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n, c, k;

	cin >> n;

	vector<int> v(n);

	for(int i = 0; i < n; i++) cin >> v[i];

	cin >> c;

	string out = "";

	while(c--)
	{
		cin >> k;
		
		int low = 0, high = k + 1, mid;

		while(high - low > 1)
		{
			mid = (high + low) / 2;

			if(f(v, mid) < k)
				low = mid;
			else
				high = mid;
			
		}
		out += "Tiempo minimo para " + to_string(k) + " trabajos es: " + to_string(high) + "\n";
	}
	
	cout << out;

	return 0;
}