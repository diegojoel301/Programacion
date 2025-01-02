#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, x = 1;

	cin >> n;
	cin.ignore();
	string cad, out = "", aux = "";

	getline(cin, cad, '\n');
	
	for(int i = 0; i < cad.size(); i++)
	{
		if(aux.size() == x)
		{
			out += aux[0];
			x++;
			aux = "";
		}
		else
		{
			aux += cad[i];
		}
	}

	out += aux[0];

	cout << out;
	
	return 0;
}