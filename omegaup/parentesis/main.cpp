#include<iostream>
#include<string>

using namespace std;

int main()
{
	string cadena;

	cin >> cadena;
	bool valida = true;
	int cuenta = 0;

	for(int i = 0; i < cadena.size(); i++)
	{
		if(cadena[i] == '(')
			cuenta++;
		else
		{
			if(cuenta == 0)
			{
				valida = false;
				break;
			}
			else
				cuenta--;
		}
	}

	if(cuenta > 0)
		valida = false;

	if(valida)
		cout << "SI\n";
	else
		cout << "NO\n";
	return 0;
}