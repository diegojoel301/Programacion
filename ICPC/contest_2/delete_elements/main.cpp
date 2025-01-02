#include<iostream>
#include<queue>

using namespace std;

bool solucion(queue<int> a);
queue<int> eliminar(queue<int> a, int i);
int getPosMn(queue<int> a);
int getElem(queue<int> a, int pos);
void mostrar(queue<int> a);

int main()
{
	int t;
	cin >> t;
	for(int j = 0; j < t; j++)
	{
		queue<int> c;
		int n;

		cin >> n;

		for(int i = 0, elem; i < n; i++)
		{
			cin >> elem;
			c.push(elem);
		}

		if(solucion(c))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

bool solucion(queue<int> a)
{
	if(a.size() != 1)
	{
		queue<int> al1, al2;
		int posMn = getPosMn(a);

		if(posMn == a.size() - 1)
			return false;

		if(getElem(a, posMn) < getElem(a, posMn + 1))
		{
			al1 = eliminar(a, posMn);
			al2 = eliminar(a, posMn + 1);
		}
		
		return solucion(al1) || solucion(al2);		
	}
	else
		return true;
}


queue<int> eliminar(queue<int> a, int i)
{
	int nroElementos = a.size();

	for(int j = 0, elem; j < nroElementos; j++)
	{
		elem = a.front();
		if(i != j)
			a.push(elem);
		a.pop();
	}
	return a;
}

int getPosMn(queue<int> a)
{
	int nroElementos = a.size(), pos = -1, mn = 999999999;

	for(int j = 0, elem; j < nroElementos; j++)
	{
		elem = a.front();

		if(elem < mn)
		{
			mn = elem;
			pos = j;
		}

		a.pop();
		a.push(elem);

	}
	return pos;
}

int getElem(queue<int> a, int pos)
{
	int nroElementos = a.size(), x = -1;

	for(int j = 0, elem; j < nroElementos; j++)
	{
		elem = a.front();

		if(j == pos)
			x = elem;

		a.pop();
		a.push(elem);
	}
	return x;
}

void mostrar(queue<int> a)
{
	if(not a.empty())
	{
		int elem = a.front();
		cout << elem << " ";
		a.pop();
		mostrar(a);
		a.push(elem);

	}
	else
		cout << "\n";
}