#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, aux, i;
	bool state;
	string cad;

	cin >> n; 
	cin.ignore();
	while(n--)
	{
		getline(cin, cad);
		state = true;
		aux = -1;
		i = 0;

		map<char, int> mapa;
		map<char, int>::iterator itr;

		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] != ' ')
				mapa[cad[i]]++;
		}

		for(itr = mapa.begin(); itr != mapa.end(); itr++)
		{
			if(i == 0)
				aux = itr->second;
			else
			{
				if(aux != itr->second)
					state = false;
			}
			i++;
		}
		if(state)
			cout << "No te lo tomes enserio\n";
		else
			cout << "Meh\n";
	}

	return 0;
}