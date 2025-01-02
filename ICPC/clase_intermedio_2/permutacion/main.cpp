#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int A[N], n;

bool estado[N];

void permutacion(vector<int> V)
{
	if(V.size() == n)
	{
		cout << "PERMUTACION\n";

		for(int i = 0; i < V.size(); i++)
			cout << V[i] << " ";
		cout << "\n";
		return;
	}

	for(int i = 0; i < n; i++)
	{
		if(not estado[i])
		{
			estado[i] = true;
			permutacion(V);
			V.push_back(A[i]);
			permutacion(V);
			estado[i] = false;
			V.pop_back();
		}
	}

}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> A[i];
	/*
	vector<int> V;
	permutacion(V);
	*/

	do
	{
		for(int i = 0; i < n; i++)
			cout << A[i] << ", ";
		cout << "\n";
	}while(next_permutation(A, A + n));

	return 0;
}