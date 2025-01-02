#include<bits/stdc++.h>

using namespace std;

string multiply(string a, int n)
{
	if(n == 0)
		return "";
	else
		return a + multiply(a, n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int my;

	while(true)
	{
		cin >> s;

		my = -1;

		if(s == ".")
			break;

		for(int i = 1, longitud, n; i < sqrt(s.size()); i++)
		{
			string scad = s.substr(0, i);
			n = s.size() / scad.size();

			if(s == multiply(scad, n))
			{
				if(n > my)
					my = n;
			}
		}

		if(my == -1)
			cout << "1\n";
		else
			cout << my <<"\n";
	}

	return 0;
}