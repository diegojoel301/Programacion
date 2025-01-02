#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, a = 0, b = 0, izq, der;

	cin >> n;

	deque<int> v;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	for(int i = 1; i <= n; i++)
	{
		izq = v.front();
		der = v.back();
		if(i % 2 != 0) // Turno de Alicia
		{
			a += max(izq, der);
			if(izq > der)
				v.pop_front();
			else
				v.pop_back();
		}
		else
		{
			b += max(izq, der);
			if(izq > der)
				v.pop_front();
			else
				v.pop_back();
		}

	}

	cout << a << "\n";
	cout << b; 

	return 0;
}