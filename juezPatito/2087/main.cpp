#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, w, mn = 99999999;
	double maximal = 0;

	vector<int> ninos, ninas;

	cin >> n >> w;

	for(int i = 0, value; i < n; i++) // niños
	{
		cin >> value;
		ninos.push_back(value);
	}

	for(int i = 0, value; i < n; i++) // niñas
	{
		cin >> value;
		ninas.push_back(value);

		if(mn > value)
			mn = value;
	}
	bool flag = true;
	double i = 0;

	for(i = 0; i <= mn and flag; i += 0.1)
	{
		double inicio = n * i;
		cout << i << "\n";
		if(maximal > w)
			flag = false;

		for(int j = 0; j < n and flag; j++)
		{
			if(ninos[j] < 2 * i)
				flag = false;
		}
		if(not flag)
			break;
		if(maximal < (n * 2 * i) + inicio and flag)
			maximal = (n * 2 * i) + inicio;
	}
	cout << maximal << "\n";
	
	
	return 0;
}
