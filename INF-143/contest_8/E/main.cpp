#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	string cipher, line, salida;

	vector<string> salidas;

	while(cin >> cipher)
	{
		map<char, char> mapa;

		line = salida = "";		

		for(int i = 0, chr = 97; i < cipher.size(); i++, chr++)
			mapa[cipher[i]] = chr;
		mapa[' '] = ' ';
		
		int n;

		cin >> n;

		n++;

		while(n--)
		{
			getline(cin, line, '\n');

			for(int i = 0; i < line.size(); i++)
			{
				salida += mapa[line[i]];
			}

			salida += "\n";
		}

		salidas.push_back(salida.substr(1, salida.size()-1));
	}

	for(int i = 0; i < salidas.size() - 1; i++)
		cout << salidas[i] << "\n";
	cout << salidas[salidas.size() - 1];

	return 0;
}