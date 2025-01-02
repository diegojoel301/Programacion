#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int V; //nro de vertices

	//lista de adyacencia

	list<int> *adj;

public:
	Graph(int V); //Constructor

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	memset(visited, false, sizeof(visited));

	//creando la lista para BFS

	list<int> queue;

	visited[s] = true;
	queue.push_back(s); // s: source nuestro nodo padre sera el primero que introduciremos en nuestra cola

	list<int>::iterator i; // este sera el iterador que nos ayudara a alamacenar los nodos adayacentes al vertice padre

	while(not queue.empty()) // recorremos hasta que la cola este vacia
	{
		s = queue.front(); // ahora el padre sera el primer elemento que saldra de la cola

		cout << s << " "; //mostrar dicho elemento

		queue.pop_front(); // lo sacamos de la cola

 
		for(i = adj[s].begin(); i != adj[s].end(); ++i) // de ese mismo nodo padre recorremos sus nodos adyacentes
		{
			if(not visited[*i]) // si ese nodo no fue visitado entonces ahora se pondra en estado de visitado y se lo agregara a la cola
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "BFS\n";

	g.BFS(2);
	return 0;
}
