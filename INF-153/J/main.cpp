#include<bits/stdc++.h>

using namespace std;

void programa(int a, int b)
{
	int comodin_1;

	cin >> comodin_1;

	string vector, elem = "";

	cin.ignore();

	getline(cin, vector);

	int i = 0, ans = 0;

	ciclo_1:
	{
		if(vector[i] != ' ') goto condicion_2;
		{
			int val = stoi(elem);
			elem = "";
			if(a > val or val > b) goto condicion_3;
				ans += val;
			goto condicion_3;
		}
		condicion_2:
		{
			elem += vector[i];
			goto condicion_3;
		}

		condicion_3: i++;
	}
	if(i < vector.size()) goto ciclo_1;

	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b;

	bool comodin = false;

	ciclo:
		if(not comodin) goto condicion;
			programa(a, b);
		condicion: comodin = true;
	if(cin >> a >> b) goto ciclo;
	
	return 0;
}