#include<bits/stdc++.h>

using namespace std;

int main()
{
	bool variable = false;
	// tipo_variable nombre_variable = valor;

	//bool --> {1, 0} (boolean)
	//int --> {-2, -1, 0, 1, 2, 3, 4, ....} (integer)
	//char --> {'a', 'b', 'c', ....} (character)
	//string --> {"gabo pvto", "negro salinas", "caca"} (string)
	
	bool variable_bool = true;

	int variable_int = 5;

	char variable_char = 'A';

	string variable_string = "caca";

	//cout << variable_bool << "\n" << variable_int << "\n" << variable_string << "\n";
	/*
	int var;

	string mensaje = "Introduceme una variable entera por el culo: ";

	cout << mensaje;

	cin >> var;

	string mensaje_2 = "La variable q esta en mi culo es: ";

	cout << mensaje_2 << var << "\n";
	*/

	/*
	if(Condicion) 
	{
		SI condicion es Verdad 
	}
	else
	{
		SI condicion es Falso
	}

	if(gabo es negro?) 
	{
		SI es muuy negro xD
	}
	else
	{
		No gabo no es negro
	}

	*/
	/*
	if(5 != 5) // 1 es distinto que 5
	{
		cout << "Si 1 es distinto que 5\n";
	}
	else
	{
		cout << "No 1 no es distinto que 5\n";
	}
	*/

	//for(inicio; condicion; incremento)
	//{
	//	codigo
	//}

	//while(condicion)
	//{
	//	 codigo
	//}

	int total_vueltas = 0;

	for(int vueltas = 3; vueltas >= total_vueltas; vueltas = vueltas - 1)
	{
		cout << "Estoy en la vuelta: " << vueltas << "\n";
	}

	return 0;
}