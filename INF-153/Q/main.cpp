#include<bits/stdc++.h>

using namespace std;

bool verifica(vector<int> v, int m, int pos)
{
	int k = v[pos];

	int i = 0;

	ciclo_2:
		if(k != m) goto condicion_2;
			return true;
		condicion_2: k = v[k];
	if(i++ < 1000) goto ciclo_2;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, i = 0;
	cin >> n >> m;

	vector<int> v(n);
	n--;

	ciclo_1:
		cin >> v[i];
	if(n != i++) goto ciclo_1;
	
	if(not verifica(v, m, 0)) goto condicion_1;
	{
		cout << "SI";
		return 0;
	}
	condicion_1: cout << "NO";
	return 0;
}