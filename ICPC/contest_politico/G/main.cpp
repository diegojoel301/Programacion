#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, pos = 0;

	cin >> n;

	cin.ignore();

	vector<string> v;

	bitset<10> aux;

	for(int j = 0; j < n; j++)
	{
		string cad;

		cin >> cad;

		v.push_back(cad);

		bitset<10> bt;
	
		for(int i = 0; i < cad.size(); i++)
			bt[i] = (cad[i] == 'a');

		if(j == 0)
			aux = bt;
		else
		{
			cout << aux
		}


	}


	return 0;
}