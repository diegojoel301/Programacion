#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, tam;
vector<int> v1, v2;

void mostrar(vector<int> a, vector<int> b)
{
	for(int i = 0; i < tam; i++)
	{
		if(i < tam / 2)
			cout << a[i] << " ";
		else	
			cout << b[i - tam / 2] << " ";
	}
	cout << "\n";
}

int main()
{
	cin >> n >> k;
	tam = pow(2, n);

	for(int i = 1, value; i <= tam; i++)
	{
		cin >> value;
		if(i <= tam / 2)
			v1.push_back(value);
		else	
			v2.push_back(value);
	}

	
	if(k % 2 != 0)
	{
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		mostrar(v2, v1);
	}
	else
		mostrar(v1, v2);
}