#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c = 0;
	char str_bits[100];
	cin >> n;
	cin.ignore();
	cin.getline(str_bits, n);

	for(int i = 0; i < n; i++)
	{
		if(str_bits[i] == '1')
			c++;
		else
			break;
	}
	cout << c + 1 << "\n";

	return 0;
}