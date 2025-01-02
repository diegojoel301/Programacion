#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, contador;
	bool sw;

	while(t--)
	{
		cin >> n;
		contador = 0;
		sw = true;

		while(n--)
		{
			string str;
			cin >> str;

			if(str == "porque")
				sw = false;

			if(sw)
				contador++;

		}

		cout << contador << "\n";
	}

	return 0;
}