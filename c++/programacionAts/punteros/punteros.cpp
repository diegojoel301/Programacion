#include<iostream>

using namespace std;

int main()
{
	int numeros[] = {1, 2, 3, 4, 5};
	int *dirNum;

	dirNum = numeros;

	for(int i = 0; i < 5; i++)
		cout << "Elemento del vector [" << i << "]: " << dirNum++ << "\n";

	return 0;
}