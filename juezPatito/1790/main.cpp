#include <bits/stdc++.h>

using namespace std;

int mAdy[5][5] = {
	{0, 1, 0, 0, 1},
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{1, 0, 0, 0, 1},
	{0, 1, 1, 0, 0}
};

int main()
{
	int T;
	string f1, f2;
	bool sf1, sf2;
	map<string , int> nodos;

	nodos.insert(pair<string, int>("Spock", 0));
	nodos.insert(pair<string, int>("Tijeras", 1));
	nodos.insert(pair<string, int>("Rata", 2));
	nodos.insert(pair<string, int>("Papel", 3));
	nodos.insert(pair<string, int>("Roca", 4));
	cin >> T;
	while(T--)
	{
		cin >> f1 >> f2;
		sf1 = mAdy[nodos[f1]][nodos[f2]];
		sf2 = mAdy[nodos[f2]][nodos[f1]];

		if(sf1 and not sf2)
			cout << "Fanatico#1\n";
		else if(not sf1 and sf2)
			cout << "Fanatico#2\n";
		else
			cout << "Empate\n";
	}

}