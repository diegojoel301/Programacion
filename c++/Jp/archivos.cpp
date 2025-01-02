#include<iostream>
#include<fstream> //esta libreria sirve para la creacion de archivos
#include<string>

using namespace std;

int main()
{
	//ofstream archivo;//objeto de la clase ofstream

	string nombreArchivo;
	char cad[100];

	cout << "Introduce el nombre del archivo a escribir: "; 
	cin >> nombreArchivo;

	cout << "Introduce el contenido que deseas escribir: "; 
	cin >> cad;
	/*
	archivo.open("datos.txt");
	
	archivo << "Gabo negro" << "\n";
	archivo << "Chauca puto" << "\n";
	archivo << "Roger Homosexual" << "\n";
	
	*/

	archivo << cad << "\n";

	archivo.close();
	
	return 0;
}
