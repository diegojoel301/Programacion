#include<bits/stdc++.h>

using namespace std;

const int N = 20;

int apagar(int x, int i) // apagar el i-esimo bit
{
	return x & ~(1 << i);
}

int encender(int x, int i)
{
	return x | (1 << i);
}

bool verifica(int x, int i)
{
	return x & (1 << i) != 0;
}

int main()
{
	/*
	int n = 10;
	int m = (n << 1);
	int x = (m << 1);
	int y = (x << 1);

	cout << (1 << 3) << "\n";
	*/
	// right shift => desplazamiento a la derecha

	// n >> 1 --> n / 2

	vector<int> A = {1, 2, 3, 4};
	int n = 4;
	bool state[n];

	memset(state, n, sizeof state);

	for(int i = 0; i < (1 << n); i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(((1 << j) & i) != 0)
				state[j] = true;
			else
				state[j] = false;
		}

		for(int j = 0; j < n; j++)
		{
			if(state[j])
				cout << A[j] << " ";
		}
		cout << "\n";
	}

	return 0;
}