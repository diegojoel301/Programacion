#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	return (x * (x + 1)) / 2;
}

void programa(int n)
{
	int i = 0;

	if(n == 0) goto condicion_1;
	{
		n--;

		string out = "";

		ciclo:
			out += to_string(f((2 * i) + 1)) + " ";
			i++;
		if(n--) goto ciclo;

		cout << out.substr(0, out.size() - 1) << "\n";
		return;
	}
	condicion_1: 

	cout << "0\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	bool comodin = false;

	ciclo_1:
		if(not comodin) goto condicion_2;
			programa(n);
		condicion_2: comodin = true;
	if(cin >> n) goto ciclo_1;

	return 0;
}