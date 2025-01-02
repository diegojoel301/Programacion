#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	int v[n];

	for(int i = 0; i < n; i++)
		cin >> v[i];

	int q; // numero de consultas

	cin >> q;

	while(q--)
	{
		int x; // el elemento a buscar
		cin >> x;
		int low = 0, high = n - 1;

		while(high - low > 1)
		{
			int mid = (high + low) / 2;

			if(v[mid] <= x)
				low = mid;
			else
				high = mid;
		}
		// siempre low es el resultado
		if(v[low] == x)
			cout << "Existe" << "\n";
		else
			cout << "No Existe" << "\n";
	}
	
	return 0;
}