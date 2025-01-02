#include<bits/stdc++.h>

using namespace std;

bool marca[10e8];

int main()
{
	int N = 10e8;
	for(int i = 2; i < N; i++)
	{
		if(marca[i] != 0) continue;
		cout << i << "\n";
		for(int j = i + i; j < N; j += i)
			marca[j] = 1;
	}
	return 0;
}