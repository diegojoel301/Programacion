#include<iostream>
#include<string>

using namespace std;

void llenarMat(int m[10][10], int N);
void mostrar(int m[10][10], int N);
void cambiar_filas(int m[10][10], int N, int a, int b);
void cambiar_columnas(int m[10][10], int N, int a, int b);
void inc(int m[10][10], int N);
void dec(int m[10][10], int N);
void transpuesta(int m[10][10], int N);

int main()
{
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++)
	{
		int N, op;
		cin >> N;
		int m[10][10];

		llenarMat(m, N);

		cin >> op;
		string operation;
		for(int i = 0, a, b; i < op; i++)
		{
			cin >> operation;
			if(operation == "transpose")
				transpuesta(m, N);
			else
			{
				if(operation == "inc")
					inc(m, N);
				else if(operation == "dec")
					dec(m, N);
				else
				{
					cin >> a >> b;
					if(operation == "row")
						cambiar_filas(m, N, a - 1, b - 1);
					else if(operation == "col")
						cambiar_columnas(m, N, a - 1, b - 1);
				}
				
			}
		}
		cout << "Case #" << k <<"\n";
		mostrar(m, N);
		cout << "\n";
	}
	return 0;
}

void llenarMat(int m[10][10], int N)
{
	char fila[N];
	for(int i = 0; i < N; i++)
	{
		cin >> fila;

		for(int j = 0; j < N; j++)
			m[i][j] = (int)fila[j] - 48;
	}
}

void mostrar(int m[10][10], int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cout << m[i][j];
		cout << "\n";
	}
}

void cambiar_filas(int m[10][10], int N, int a, int b)
{
	for(int i = 0, tmp; i < N; i++)
	{
		tmp = m[b][i];
		m[b][i] = m[a][i];
		m[a][i] = tmp;
	}
}
void cambiar_columnas(int m[10][10], int N, int a, int b)
{
	for(int i = 0, tmp; i < N; i++)
	{
		tmp = m[i][b];
		m[i][b] = m[i][a];
		m[i][a] = tmp;
	}
}
void transpuesta(int m[10][10], int N)
{
	int aux[10][10];

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			aux[j][i] = m[i][j];
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			m[i][j] = aux[i][j];
	}
}

void inc(int m[10][10], int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			m[i][j] = (m[i][j] + 1) % 10;
	}
}

void dec(int m[10][10], int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(m[i][j] - 1 == -1)
				m[i][j] = 9;
			else
				m[i][j] -= 1;
		}
	}
}