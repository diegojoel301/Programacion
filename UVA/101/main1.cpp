#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
#include<stdio.h>

using namespace std;

vector<stack<int>> v;
stack<int> aux;

void vaciar(stack<int> a, stack<int> b);
void llenarVector(int n);
void mostrarVector(int n);
void moveAoverB(int a, int b, int n);
void eliminaElemento(int pos, int x);
int posicion(int n, int x);
bool verifica(stack<int> a, int x);
void elementosStack(stack<int> a, string x);
void moveAontoB(int a, int b, int n);
void moveonto(int pos, int x, int y);
void eliminaStack(int pos, int x, int y);
void pileAoverB(int a, int b, int n);
void pileAontoB(int a, int b, int n);
void moveStackonto(int pos, int x, int pos2);

int main()
{
	int n, a, b;

	cin >> n;

	llenarVector(n);
	
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
	mostrarVector(n);
	return 0;
}

void llenarVector(int n)
{
	for(int i = 0; i < n; i++)
	{
		stack<int> nue;
		nue.push(i);
		v.push_back(nue);
	}
}
void mostrarVector(int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << i << ":";
		elementosStack(v[i], " ");
		cout << "\n";
	}
	
}
void elementosStack(stack<int> a, string x)
{
	if(not a.empty())
	{
		int e = a.top();
		a.pop();
		elementosStack(a, x);
		cout << to_string(e) << " ";
		a.push(e);
	}
}

void vaciar(stack<int> a, stack<int> b)
{
	if(not b.empty())
	{
		a.push(b.top());
		b.pop();
		vaciar(a, b);
	}
	
}

bool verifica(stack<int> a, int x)
{
	if(not a.empty())
	{
		int e = a.top();
		a.pop();
		aux.push(e);

		if(e == x)
		{
			vaciar(a, aux);
			return true;
		}
		else
			return verifica(a, x);
	}
	else
	{
		vaciar(a, aux);
		return false;
	}

}

int posicion(int n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(verifica(v[i], x))
			return i;
	}
	return -1;
}

void eliminaElemento(int pos, int x)
{	
	while(not v[pos].empty())
	{
		int e = v[pos].top();
		
		if(e != x)
		{
			v[e].push(e);
			v[pos].pop();
		}
		else
		{
			v[pos].pop();
			break;
		}
		
	}
}

void moveAoverB(int a, int b, int n)
{
	int pos1 = posicion(n, a), pos2 = posicion(n, b);

	if(pos1 != pos2)
	{
		eliminaElemento(pos1, a);
		v[pos2].push(a);
	}
}

void moveAontoB(int a, int b, int n)
{
	int pos1 = posicion(n, a), pos2 = posicion(n, b);

	if(pos1 != pos2)
	{
		eliminaElemento(pos1, a);
		moveonto(pos2, b, a);
	}
}

void moveonto(int pos, int x, int y)
{
	while(not v[pos].empty())
	{
		int e = v[pos].top();
		
		if(e != x)
		{
			v[e].push(e);
			v[pos].pop();
		}
		else
		{
			v[pos].push(y);
			break;
		}
		
	}
}

void eliminaStack(int pos, int x, int pos2)
{	
	if(v[pos].top() != x and not v[pos].empty())
	{
		int e = v[pos].top();
		v[pos].pop();
		eliminaStack(pos, x, pos2);
		v[pos2].push(e);
	}
	else
	{
		v[pos2].push(v[pos].top());
		v[pos].pop();
	}
}

void pileAoverB(int a, int b, int n)
{
	int pos1 = posicion(n, a), pos2 = posicion(n, b);

	if(pos1 != pos2)
		eliminaStack(pos1, a, pos2);
}


void pileAontoB(int a, int b, int n)
{
	int pos1 = posicion(n, a), pos2 = posicion(n, b);

	if(pos1 != pos2)
	{
		moveonto(pos2, b, -1);
		v[pos2].pop();
		eliminaStack(pos1, a, pos2);
	}
}

