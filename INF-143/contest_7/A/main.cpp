#include<bits/stdc++.h>

using namespace std;

string limpieza(string cad)
{
	string ncad = "";
	char nchar;
	for(int i = 0, ascii; i < cad.size(); i++)
	{
		ascii = cad[i];

		if(65 <= ascii and ascii <= 90)
		{
			nchar = ascii + 32;
			ncad += nchar;
		}
		else if(97 <= ascii and ascii <= 122)
			ncad += cad[i];

	}

	return ncad;
}

int main()
{
	freopen("input1.txt", "r", stdin);

	vector<string> v;

	string elem;

	while(cin >> elem)
		v.push_back(limpieza(elem));

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";


	return 0;
}