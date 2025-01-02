#include<iostream>
#include <vector>

using namespace std;

vector<int> graph[10000];
int n, m;

int main()
{
	//implementacion grafo lista de adyacencia
	
	cin >> n >> m;

	graph.resize(n);

	for(int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}	

	return 0;
}