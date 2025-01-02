#include<bits/stdc++.h>

using namespace std;

vector<int> sol;

void solucion(int a, int b)
{
	if(a == 1)
		return;
	else
	{
		sol.push_back(a / b);

		return solucion(b, a % b);
	}
	
}

int main()
{
	int a, b;

	while(cin >> a >> b)
	{
		sol.clear();
		if(a == 1)
		{
			sol.push_back(0);
			sol.push_back(b);
		}
		else
		{
			solucion(a, b);
		}

		cout << "[" << sol[0] << ";";
		for(int i = 1; i < sol.size() - 1; i++)
			cout << sol[i] << ",";
		cout << sol[sol.size() - 1] << "]\n";
	}

	return 0;
}