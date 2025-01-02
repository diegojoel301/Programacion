#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<vector>

using namespace std;

vector<vector<int> > m(25, vector<int>(25, -1));

void llenar(int n);
void mostrar(int n);
int localiza(int x, int n);
void excavaA(int pos, int x);
void adicionarElemento(int pos, int x);
void moveAoverB(int a, int b, int n);
void moveAontoB(int a, int b, int n);
void enpilar(int pos1, int pos2, int a);
void pileAoverB(int a, int b, int n);
void pileAontoB(int a, int b, int n);

int main()
{
	
	int n, a, b;

	cin >> n;

	llenar(n);
	
	char input[50], x[10], y[10];
	
	
	while(true)
	{
		cin >> x;

		if(strcmp(x, "quit") == 0)
			break;
		cin >> a;
		if(strcmp(x, "move") == 0)
		{
			cin >> y;
			cin >> b;
			if(strcmp(y, "onto") == 0)
				moveAontoB(a, b, n);
			else if(strcmp(y, "over") == 0)
				moveAoverB(a, b, n);

		}

		if(strcmp(x, "pile") == 0)
		{
			cin >> y;
			cin >> b;
			if(strcmp(y, "onto") == 0)
				pileAontoB(a, b, n);
			else if(strcmp(y, "over") == 0)
				pileAoverB(a, b, n);
		}
		
	}
	
	mostrar(n);
	return 0;
}

void llenar(int n)
{
	for(int i = 0; i < n; i++) m[i][0] = i;
}
void mostrar(int n)
{
	int j;

	for(int i = 0; i < n; i++)
	{
		j = 0;
		cout << i << ":";
		string cad = " ";
		while(m[i][j] != -1)
		{
			cad += to_string(m[i][j]) + " ";
			j++;
		}
		cout << cad.substr(0, cad.length() - 1) << "\n";
	}
}
int localiza(int x, int n)
{
	int j;
	for(int i = 0; i < n; i++)
	{
		j = 0;
		while(m[i][j] != -1)
		{
			if(m[i][j] == x)
				return i;
			j++;
		}
	}
	return -1;
}
void excavaA(int pos, int x)
{
	int j = 0;
	bool sw = false;

	while(m[pos][j] != -1)
	{
		if(sw)
		{
			m[m[pos][j]][0] = m[pos][j];
			m[pos][j] = -1;
		}
		else
		{
			if(m[pos][j] == x)
			{
				m[pos][j] = -1;
				sw = true;
			}
		}
		j++;
	}
}
void adicionarElemento(int pos, int x)
{
	int j = 0;
	while(m[pos][j] != - 1)
		j++;
	m[pos][j] = x;
}

void moveAoverB(int a, int b, int n)
{
	int pos1 = localiza(a, n), pos2 = localiza(b, n);

	if(pos1 != pos2)
	{
		excavaA(pos1, a);
		adicionarElemento(pos2, a);
	}
}

void moveAontoB(int a, int b, int n)
{
	int pos1 = localiza(a, n), pos2 = localiza(b, n);
	if(pos1 != pos2)
	{
		excavaA(pos1, a);
		excavaA(pos2, b);

		adicionarElemento(pos2, b);
		adicionarElemento(pos2, a);
	}
}

void enpilar(int pos1, int pos2, int a)
{
	int j = 0;
	bool sw = false;

	while(m[pos1][j] != -1)
	{
		if(sw == true)
		{
			adicionarElemento(pos2, m[pos1][j]);
			m[pos1][j] = -1;
		}
		else
		{
			if(m[pos1][j] == a)
			{
				adicionarElemento(pos2, m[pos1][j]);
				m[pos1][j] = -1;
				sw = true;
			}
		}
		j++;
	}
}

void pileAoverB(int a, int b, int n)
{
	int pos1 = localiza(a, n), pos2 = localiza(b, n);
	if(pos1 != pos2)
		enpilar(pos1, pos2, a);
}

void pileAontoB(int a, int b, int n)
{
	int pos1 = localiza(a, n), pos2 = localiza(b, n);

	if(pos1 != pos2)
	{
		excavaA(pos2, b);
		adicionarElemento(pos2, b);
		enpilar(pos1, pos2, a);
	}
}