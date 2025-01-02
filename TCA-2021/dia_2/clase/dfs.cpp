#include<iostream>
#include<queue>

using namespace std;

vector adj[N];
bool visited[N];

void dfs(int s)
{
	if(visited[s]) return;
	visited[s] = true;

	for(auto u: adj[s])
		dfs(u);
}

int main()
{
	return 0;
}