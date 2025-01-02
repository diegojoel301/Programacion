#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	while(cin >> n)
	{
		int A[n + 5];

		for(int i = 0; i < n; i++)
			cin >> A[i];

		int contador = 0;

		for(int i = 0; i < n; i++)
		{
			if(A[i] == A[n - 1])
				contador++;
		}
		cout << contador << "\n";
	}

	return 0;
}