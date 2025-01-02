#include<bits/stdc++.h>

using namespace std;

const int N = 1e3;
int n;

int v[N];
bool estado[N];

void permutation(vector<int> &A)
{
	if(A.size() == n)
	{
		for(int i = 0; i < A.size(); i++)
			cout << A[i] << " ";
		cout << "\n";
		return;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(not estado[i])
			{
				estado[i] = true;
				A.push_back(v[i]);
				permutation(A);
				estado[i] = false;
				A.pop_back();
			}
		}
	}
}

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> A;

	permutation(A);
	/*
	do
	{
		for(int i = 0; i < n; i++)
			cout << v[i] << " ";
		cout << "\n";
	}while(next_permutation(v, v + n));
	*/
	return 0;
}