#include<bits/stdc++.h>

using namespace std;

vector<map<int, int>> f(1001);

map<int, int> factorizacion(int n)
{
	map<int, int> mapa;

	while(n % 2 == 0)
	{
		mapa[2] += 1;
		n /= 2;
	}

	for(int i = 3; i * i <= n; i = i + 2)
	{
		while(n % i == 0)
		{
			mapa[i] += 1;
			n = n/i;
		}
	}

	if(n > 2)
		mapa[n] += 1;

	return mapa;
}

map<int, int> union_map(map<int, int> A, map<int, int> B)
{
	map<int, int>::iterator itr;
	
	for(itr = A.begin(); itr != A.end(); ++itr)
		B[itr->first] += itr->second;

	return B;
}

void gen()
{
	f[2] = factorizacion(2);

	for(int i = 3; i <= 1000; i++)
		f[i] = union_map(f[i - 1], factorizacion(i));
}

int main()
{
	gen();
	vector<string> soluciones(1001);

	for(int i = 2; i <= 1000; i++)
	{
		map<int, int>::iterator itr;
		string out = "";
		
		for(itr = f[i].begin(); itr != f[i].end(); ++itr)
			out += to_string(itr->first) + "(" + to_string(itr->second) + ")" + "*";
		out += "\n";
		soluciones[i] = out.substr(0, out.size() - 2) + "\n";		
	}
	
	int t, n;
	while(cin >> t)
	{
		while(t--)
		{
			cin >> n;
			cout << soluciones[n];
		}
	}

	return 0;
}