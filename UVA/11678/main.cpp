#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int nA = - 1, nB = -1;

void maximo(vector<int> A, vector<int> B)
{
	int interseccion = 0;

	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < B.size(); j++) if(A[i] == B[j]) interseccion++;
	}

	cout << min(A.size() - interseccion, B.size() - interseccion) << "\n";
}

int main()
{

	while(nA != 0 and nB != 0)
	{
		vector<int> A, B;
		cin >> nA;
		cin >> nB;	

		if(nA == 0 and nB == 0) break;

		for(int i = 0, value; i < nA; i++)
		{
			cin >> value;
			A.push_back(value);
		}

		for(int i = 0, value; i < nB; i++)
		{
			cin >> value;
			B.push_back(value);
		}

		sort( A.begin(), A.end() );
		A.erase(unique(A.begin(), A.end()), A.end());

		sort( B.begin(), B.end() );
		B.erase(unique(B.begin(), B.end()), B.end());

		maximo(A, B);
	}
	return 0;
}
