#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v; //(antiguos, nuevos)

void gen(string cad)
{
	int cA = 0, cN = 0;

	for(int i = 0; i < cad.size(); i++)
	{
		pair<int, int> x;

		if(cad[i] == 'A')
			cA++;
		else
			cN++;

		x.first = cA;
		x.second = cN;

		v.push_back(x);
	}
}

int main()
{
	string P;

	int m, L, R, x, y, a, b, add1, add2;

	cin >> P;

	gen(P);
	
	cin >> m;

	while(m--)
	{
		cin >> L >> R;
		add1 = add2 = 0;
		x = v[L].first;
		y = v[L].second;

		a = v[R].first;
		b = v[R].second;

		if(P[L] == 'N')
			add2 = 1;
		else
			add1 = 1;

		cout << a - x + add1 << " " << b - y + add2 << "\n";
	}
	return 0;
}