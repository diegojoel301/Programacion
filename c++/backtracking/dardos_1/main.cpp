#include<bits/stdc++.h>

using namespace std;

int calcularPuntutacion(vector<int> zonas, vector<int> regionesDadas)
{
	int puntos = 0;

	for(int i = 0; i < regionesDadas.size(); i++)
		puntos += zonas[i] * regionesDadas[i];
	return puntos;
}

bool dardosV1(vector<int> &solucion, vector<int> &zonas, vector<int> &regionesDadas, int dardos, int etapa, int puntuacionActual, int puntuacionIgualar)
{
	bool fin = false;

	if(dardos == 0 or etapa == zonas.size() or calcularPuntutacion(zonas, regionesDadas) == puntuacionIgualar) //me quedo sin dardos
	{
		if(calcularPuntutacion(zonas, regionesDadas) == puntuacionIgualar)
		{
			for(int i = 0; i < zonas.size(); i++)
				solucion[i] = zonas[i];	
			fin = true;
		}
	}
	else
	{
		for(int d = 0; d <= dardos; d++)
		{
			int puntuacionZona = zonas[etapa] * d;

			puntuacionActual += puntuacionZona;

			if(puntuacionActual <= puntuacionIgualar)
			{
				regionesDadas[etapa] = d;

				fin = dardosV1(solucion, zonas, regionesDadas, dardos - d, etapa + 1, puntuacionActual, puntuacionIgualar);

				regionesDadas[etapa] = 0;
			}
		}
	}

	return fin;
}

void mostrarSolucion(vector<int> zonas, vector<int> regionesDadas)
{
	for(int i = 0; i < regionesDadas.size(); i++)
	{
		if(regionesDadas[i] != 0)
		{
			for(int j = 0; j < regionesDadas[i]; j++)
				cout << zonas[i] << " ";
		}
	}
	cout << "\n";
}

int main()
{
	vector<int>zonas = {10, 25, 50, 75};
	vector<int>regionesDadas(zonas.size()), solucion(zonas.size());
	int dardos = 5, puntuacion = 100, etapa = 0;

	dardosV1(solucion, zonas, regionesDadas, dardos, etapa, 0, puntuacion);

	mostrarSolucion(zonas, solucion);

	return 0;
}