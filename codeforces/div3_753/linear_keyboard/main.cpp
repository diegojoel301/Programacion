#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	int t;

	cin >> t;

	string alfabeto, cad;
	cin.ignore();
	while(t--)
	{
		getline(cin, alfabeto, '\n');
		getline(cin, cad, '\n');

		map<char, int> mapa;

		int a, b, ans = 0;

		for(int i = 0; i < alfabeto.size(); i++)
			mapa[alfabeto[i]] = i + 1;

		
		for(int i = 0; i < cad.size() - 1; i++)
		{	
			a = mapa[cad[i]];
			b = mapa[cad[i + 1]];
			//cout << "|" << a << " - " << b << "|\n";

			ans += abs(a - b);

			a = b;
		}
		cout << ans << "\n";
	}

	return 0;
}