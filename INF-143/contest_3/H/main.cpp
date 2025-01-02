#include<bits/stdc++.h>
#define M 10000
using namespace std;

string convert(bool s)
{
	if(s)
		return "R";
	return "Z";
}

bitset<M> inicio;

int main()
{
	int n, q, a, b;
	string out = "";
	cin >> n >> q;

	while(q--)
	{
		cin >> a >> b;
		bitset<M> bset1(string(b - a + 1, '1'));
		inicio = inicio ^ (bset1 << n - b);	
	}
	
	for(int i = n - 1; i >= 0; i--)
		out += convert(inicio[i]) + " ";
	cout << out.substr(0, out.size() - 1);

	return 0;
}