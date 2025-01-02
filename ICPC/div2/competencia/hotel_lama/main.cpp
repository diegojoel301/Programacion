#include<bits/stdc++.h>
#define M 100

using namespace std;

int main()
{
	int n, aux;

	cin >> n;

	aux = n;

	bitset<M> bsetf;

	while(n--)
	{
		string nbit = "", bit;

		cin >> nbit;
		
		for(int i = 0; i < nbit.size(); i++)
		{
			if(nbit[i] == 'a')
				bit += "1";
			else
				bit += "0";
		}

		bitset<M> bset(string(bit+""));	

		bsetf = bsetf ^ bset;
	}
	string out = "";

	for(int i = aux - 1; i >= 0; i--)
	{
		if(bsetf[i])
			out += "a";
		else
			out += "b";
	}

	cout << out;

	return 0;
}