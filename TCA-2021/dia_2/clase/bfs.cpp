#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q; //para procesar los vecinos
	bool visited[N]; 
	int distance[N]; 

	visited[x] = true;

	distance[x] = 0;

	q.push(x);

	while(not q.empty())
	{
		int s = q.front(); q.pop();
		//procesando nodo s
		for(auto u : adj[s])
		{
			if(visited[u]) continue;

			visited[u] = true;
			distance[u] = distance[s] + 1;
			q.push(u);
		}
	}

	return 0;
}