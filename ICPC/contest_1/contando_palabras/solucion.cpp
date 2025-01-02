#include<bits/stdc++.h>

using namespace std;

int main()
{
	short int tamanio;

	cin >> tamanio;

	//getline(cin, cadena);
	//getline(cin, cadena);

	cin.ignore();
	getline(cin, cadena);

	int palabras = 0;

	for(int i = 0; i < cadena.size(); i++)
		if(cadena[i] == ' ') palabras++;

	cout << palabras + 1 << "\n";

	return 0;
}
