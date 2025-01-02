#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	while(n--)
	{
		string cadena;
		cin >> cadena;

		for(int i = 0; i < cadena.size(); i++)
			cout << cadena[i] << "\n";
	}


	return 0;
}