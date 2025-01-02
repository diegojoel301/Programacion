#include<bits/stdc++.h>
#define ll long long 

using namespace std;

// Criba de Eratostenes O(N)

int main()
{
	int N = 10000000, cnt = 0;
	vector<int> criba(N + 1, -1);
	vector<int> primos;

	for(int i = 2; i <= N; i++)
	{
		if(criba[i] == -1)
		{
			criba[i] = i;
			primos.push_back(i);
		}
		for(int j = 0; j < primos.size() and primos[j] <= criba[i] and i * primos[j] < N; j++)
		{
			criba[i * primos[j]] = primos[j];
			cnt++;
		}
	}
	/*
	for(int i = 0; i < N; i++)
	{
		if(criba[i])
			cout << i << "\n";
	}*/
	cout << "CNT= " << cnt << "\n";	

	return 0;
}