#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	int n, t = 1;

	while(cin >> n)
	{
		vector<string> v;

		string cad;

		map<string, int> mapa;

		for(int i = 0; i < n; i++)
		{
			cin >> cad;
			v.push_back(cad);
			//v[i] = cad;
			mapa[cad] = 0;
		}

		for(int i = 0, money, amigos; i < n; i++)
		{
			string nombre;
			cin >> nombre;
			cin >> money >> amigos;
			//cout << nombre << " " <<  money << " " << amigos << " ";
			if(amigos != 0)
				mapa[nombre] += -money + (money % amigos);

			for(int j = 0; j < amigos; j++)
			{
				cin >> nombre;
				//cout << nombre << " ";
				if(amigos != 0)
					mapa[nombre] += money / amigos;
			}
			
			//cout << "\n";
		}

		if(t++ > 1)
			cout << "\n";

		for(int i = 0; i < n; i++)
			cout << v[i] << " " << mapa[v[i]] << "\n";
	}

	return 0;
}