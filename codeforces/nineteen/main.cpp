#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<char, int> mapa;

	string cad, simp;

	cin >> cad; 

	int c = 0;

	for(int i = 0; i < cad.size(); i++)
	{
		if(cad[i] == 'n' or cad[i] == 'i' or cad[i] == 'e' or cad[i] == 't')
			mapa[cad[i]]++;
	}

	map<char, int>::iterator itr;
	
	while(mapa['n'] >= 0 and mapa['i'] >= 0 and mapa['t'] >= 0 and mapa['e'] >= 0)
	{
		if(mapa['n'] > 0 and c == 0)
			mapa['n']--;
		else if(mapa['n'] == 0)
			break;

		if(mapa['i'] > 0)
			mapa['i']--;
		else
			break;

		if(mapa['n'] > 0)
			mapa['n']--;
		else
			break;

		if(mapa['e'] > 0)
			mapa['e']--;
		else
			break;

		if(mapa['t'] > 0)
			mapa['t']--;
		else
			break;

		if(mapa['e'] > 0)
			mapa['e']--;
		else
			break;

		if(mapa['e'] > 0)
			mapa['e']--;
		else
			break;

		if(mapa['n'] > 0)
			mapa['n']--;
		else
			break;
		c++;
	}
	cout << c << "\n";

	return 0;
}