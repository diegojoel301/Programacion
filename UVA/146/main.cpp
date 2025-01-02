#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str = "-";

	while(str != "#")
	{
		str = "";
		cin >> str;

		if(str == "#")
			break;

		char cad[str.length()];

		for(int i = 0; i < str.length(); i++)
			cad[i] = str[i];

		bool state = next_permutation(cad, cad + str.length());

		if(state)
		{
			for(int i = 0; i < str.length(); i++)
				cout << cad[i];
			cout << "\n";
		}
		else
		{
			cout << "No Successor\n";
		}
	}
	return 0;
}