#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int A[N];
int n;

bool estado[N];
//0 no es parte del conjunto
//1 es parte del conjunto

void subconjuntos(int i)
{
	if(i == n)
	{
		cout << "{";

		for(int i = 0; i < n - 1; i++)
			if(estado[i])
				cout << A[i] << " ";
		if(estado[n - 1])
			cout << A[n - 1];

		cout << "}\n";

		return;
	}
	else
	{
		//no tomar al elemento
		estado[i] = 0;
		subconjuntos(i + 1);
		//tomar al elemento
		estado[i] = 1;
		subconjuntos(i + 1);
	}
	

}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> A[i];

	subconjuntos(0);

	return 0;
}