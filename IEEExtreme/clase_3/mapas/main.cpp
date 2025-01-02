#include<bits/stdc++.h>

using namespace std;

int main()
{
	map<int, string> mapa;
	mapa[12926609] = "yo pvtos";
	mapa[12345678] = "Andres";
	mapa[8746352] = "Vanesa";
	mapa.insert(make_pair(3746345, "Leydi"));
	mapa[6746334] = "Gabo";

	map<int, string>::iterator itr;

	itr = mapa.begin();

	cout << &itr->first << " " << &itr->second << "\n";
	itr++;
	cout << &itr->first << " " << &itr->second << "\n";
	itr++;
	cout << &itr->first << " " << &itr->second << "\n";
 	itr++;
	cout << &itr->first << " " << &itr->second << "\n";


	for(map<int, string>::iterator i = mapa.begin(); i != mapa.end(); i++)
		cout << i->first << " " << i->second << "\n";

	cout << "--------------------------------------------------------------------------\n";

	mapa.erase(12926609); //elimina el elemento con llave como argumento

	for(map<int, string>::iterator i = mapa.begin(); i != mapa.end(); i++)
		cout << i->first << " " << i->second << "\n";

	cout << mapa.count

	return 0;
}