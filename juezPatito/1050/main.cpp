#include<bits/stdc++.h>

using namespace std;

int n;

string decimalToBinary()
{
	string s = bitset<64> (n).to_string();

	const auto loc1 = s.find('1');

	if(loc1 != string::npos)
		return s.substr(loc1);

	return "0";
}

int main()
{
	while(cin >> n)
	{
		string binary =  decimalToBinary();
		reverse(binary.begin(), binary.end());
		unsigned long decimal = bitset<64>(binary).to_ulong();
		cout << decimal << "\n";
	}

	return 0;
}