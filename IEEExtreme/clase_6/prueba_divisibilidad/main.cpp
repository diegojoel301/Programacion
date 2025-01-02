#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	cin >> x;

	bool es_primo = true;

	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			es_primo = false;
			break;
		}
	}

	if(es_primo)
		cout << x << " es primo\n";
	else
		cout << x << " NO es primo\n";

	return 0;
}