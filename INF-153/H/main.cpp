#include<bits/stdc++.h>

using namespace std;

int programa(int n)
{
	vector<int> a(n), b(n);

	int i = 0, s = 0;

	ciclo_1:
	{
		cin >> a[i];
		i++;
	}
	if(i < n) goto ciclo_1;

	i = 0;

	ciclo_2:
	{
		cin >> b[i];
		i++;
	}
	if(i < n) goto ciclo_2;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	i = 0;

	ciclo_3:
	{
		s += (a[i] * b[i]);
		i++;
	}
	if(i < n) goto ciclo_3;

	return s;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	bool comodin = false;

	ciclo:
	{
		if(not comodin) goto condicion;
			cout << programa(n) << "\n";
		condicion: comodin = true;
	}
	if(cin >> n) goto ciclo;

	return 0;
}