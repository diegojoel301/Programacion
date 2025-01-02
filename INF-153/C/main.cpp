#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char x;

	cin >> x;

	if(not isupper(x)) goto condicion_1;
	{
		cout << (char)tolower(x);
		return 0;
	}

	condicion_1: if(not islower(x)) goto condicion_2;
	{
		cout << (char)toupper(x);
		return 0;
	}

	condicion_2: return 0;
}