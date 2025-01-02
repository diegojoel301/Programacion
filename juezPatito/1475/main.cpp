#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, i, j;

	cin >> N >> i >> j;

	vector<int> v, aux;

	for(int k = 0, value; k < N; k++)
	{
		cin >> value;

		if(i <= k and k < j)
			aux.push_back(value);
		else if(k == j)
		{
			aux.push_back(value);
			reverse(aux.begin(), aux.end());
			for(int l = 0; l < aux.size(); l++)
				v.push_back(aux[l]);
		}
		else
			v.push_back(value);
	}

	for(int k = 0; k < N; k++)
		cout << v[k] << "\n";

	return 0;
}