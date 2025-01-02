#include<bits/stdc++.h>

using namespace std;

struct mochila
{
	float valor;
	float peso;
	float indice;
};

int main()
{
	int n, max, cont;
	float wmax, valmax;

	cout << "Ingresa el numero de elementos en la mochila: ";
	cin >> n;

	mochila elemento[n], aux;

	cout << "\n Ingresar elemento en la mochila: \n";

	for(int i = 0; i < n; i++)
	{
		cout << "Valor " << i + 1 << ":";
		cin >> elemento[i].valor;
		cout << "Peso " << i + 1 << ":";
		cin >> elemento[i].peso;
		elemento[i].indice = elemento[i].valor / elemento[i].peso;
	}

	for(int i = 0; i < n; i++)
	{
		max = i;

		for(int j = i + 1; j < n; j++)
		{
			if(elemento[j].indice > elemento[max].indice)
				max = j;
			cont++;
		}
		aux = elemento[i];
		elemento[i] = elemento[max];
		elemento[max] = aux;
	}

	for(int i = 0; i < n; i++)
	{
		cout << i + 1 << " : ";
		cout << elemento[i].indice << " , ";
		cout << elemento[i].peso << " , ";
		cout << elemento[i].valor << "\n";
	}

	cout << "\n";

	cout << "Peso maximo maximo de la mochila : \n";
	cin >> wmax;

	int i = 0;

	while(wmax > 0)
	{
		if(wmax > elemento[i].peso)
		{
			wmax = wmax - elemento[i].peso;
			valmax = valmax + elemento[i].valor;
		}
		else
		{
			valmax = valmax + (elemento[i].valor * (wmax / elemento[i].peso));
			wmax = 0;
		}
		i++;
	}

	cout << "El valor maximo de la mochila es: " << valmax << " \n";

	return 0;
}
