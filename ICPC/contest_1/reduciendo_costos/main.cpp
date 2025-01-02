#include<iostream>

using namespace std;

int main()
{
	int T, A, B, C;

	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> A >> B >> C;
		cout << "El sueldo del empleado es: ";
		if((A < B and B < C) or (C < B and B < A))
			cout << B << "\n";
		if((B < A and A < C) or (C < A and A < B))
			cout << A << "\n";
		if((B < C and C < A) or (A < C and C < B))
			cout << C << "\n";
	}

	return 0;
}