#include<bits/stdc++.h>

using namespace std;

int main()
{
	string cad;

	vector<string> v;

	bool comodin = false;

	ciclo:

		if(not comodin) goto condicion;
			v.push_back(cad);

		condicion: comodin = true;

	if(getline(cin, cad)) goto ciclo;

	vector<int> calcular((int) v.size());

	int i = 0;

	ciclo_1:

		calcular[i] = 1;

		int j = 0;

		ciclo_2:

			if(v[j] >= v[i]) goto condicion_2;
				calcular[i] = max(calcular[i], calcular[j] + 1);
			condicion_2: j++;

		if(j < i) goto ciclo_2;
		i++;
	if(i < v.size()) goto ciclo_1;

	int mx = *max_element(calcular.begin(), calcular.end());
	cout << mx << "\n***\n";

	string last = "{{{{{{{{{";

	stack<string> pila;

	i = v.size() - 1;

	ciclo_3:
		if(calcular[i] != mx or last < v[i]) goto condicion_1;
		{
			mx--;
			pila.push(v[i]);
			last = v[i];
		}

		condicion_1:
		i--;
	if(i >= 0) goto ciclo_3;	

	ciclo_4:
	{
		cout << pila.top() << "\n";
		pila.pop();
	}
	if(not pila.empty()) goto ciclo_4;

	return 0;
}