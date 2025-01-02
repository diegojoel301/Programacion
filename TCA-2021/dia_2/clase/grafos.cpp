#include<iostream>

using namespace std;

int main()
{
	//implementacion grafo
	int n;
	cin >> n;
	bool graph[n][n];

	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	return 0;
}