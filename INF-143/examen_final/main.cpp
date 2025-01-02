#include<bits/stdc++.h>
#define INF 10000000

using namespace std;

map<char, int> mapa;
map<int, char> mapa1;

void llenar_mapa()
{
	for(int i = 0; i < 27; i++)
	{
		mapa['A' + i] = i;
		mapa1[i] = 'A' + i;
	}
}

void enlace(char u, char v, vector<vector<int>>& adj) // para el primer grafo no dirigido
{
	adj[mapa[u]].push_back(mapa[v]);
	adj[mapa[v]].push_back(mapa[u]);
}

void enlace1(char u, char v, vector<vector<pair<int, int>>>& adj, int weight) // para el segundo grafo dirigido y con pesos
{
	adj[mapa[u]].push_back({mapa[v], weight});
}

void llenar_grafo_1(vector<vector<int>>& adj) // llenado del primer grafo no dirigido
{
	enlace('A', 'C', adj);
	enlace('A', 'B', adj);
	enlace('B', 'C', adj);
	enlace('B', 'D', adj);
	enlace('D', 'C', adj);
	enlace('D', 'E', adj);
	enlace('D', 'F', adj);
	enlace('E', 'G', adj);
	enlace('F', 'G', adj);
	enlace('G', 'H', adj);
	enlace('F', 'H', adj);
}

void llenar_grafo_2(vector<vector<pair<int, int>>>& adj) // llenado del segundo grafo dirigido y con pesos
{
	enlace1('C', 'A', adj, 1);
	enlace1('A', 'B', adj, 1);
	enlace1('B', 'C', adj, 3);
	enlace1('B', 'D', adj, 2);
	enlace1('C', 'D', adj, 1);
	enlace1('D', 'E', adj, 3);
	enlace1('D', 'F', adj, 2);
	enlace1('E', 'G', adj, 1);
	enlace1('F', 'G', adj, 4);
	enlace1('H', 'G', adj, 1);
	enlace1('F', 'H', adj, 3);
}

bool state = false;

void dfs_enroute(int node, int targeted, vector<vector<int>>& adj, vector<bool>& vis, deque<int>& sol) // esta funcion se encarga de enumerar todos los caminos de un nodo a otro haciendo uso del recorrido DFS y backtracking
{
	if(not state)
	{
		sol.push_back(node);
		vis[node] = true;

		if(node == targeted)
		{
			int nro = sol.size();
			cout << "{";
			for(int i = 0; i < nro - 1; i++)
			{
				int elem = sol.front();
				cout << mapa1[elem] << ", ";
				sol.pop_front();
				sol.push_back(elem);
			}

			int elem = sol.front();
			cout << mapa1[elem] << "}\n";
			sol.pop_front();
			sol.push_back(elem);
			state = true;
		}
		else
		{
			for(int i = 0; i < adj[node].size(); i++)
			{
				if(not vis[adj[node][i]])
					dfs_enroute(adj[node][i], targeted, adj, vis, sol);
			}
		}
		sol.pop_back();
		vis[node] = false;
	}
}

bool no_visitado(int targeted, vector<int> v)
{
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] == targeted)
			return false;
	}
	return true;
}

void bfs_enroute(int node, int targeted, vector<vector<int>>& adj) // esta funcion se encarga de mostrar una unica solucion haciendo uso del BFS
{
	queue<vector<int>> q;
	vector<int> v;
	v.push_back(node);
	q.push(v);

	while(not q.empty())
	{
		v = q.front();
		q.pop(); 
		int ultimo_elemento = v[v.size() - 1];
		if(ultimo_elemento == targeted)
		{
			cout << "{";
			for(int i = 0; i < v.size() - 1; i++)
				cout << mapa1[v[i]] << ", ";
			cout <<mapa1[v[v.size() - 1]]<< "}\n";
			return;
		}

		for(int i = 0; i < adj[ultimo_elemento].size(); i++)
		{
			if(no_visitado(adj[ultimo_elemento][i], v))
			{
				vector<int> aux(v);
				aux.push_back(adj[ultimo_elemento][i]);
				q.push(aux);
			}
		}
	}
}

void cleaning(vector<bool>& vis) // todos los elementos del vector vis los pasa a false para proceder a otro recorrido DFS
{
	for(int i = 0; i < vis.size(); i++)
		vis[i] = false;
}

void absolute_router(int node, int targeted, vector<vector<int>>& adj, vector<bool>& vis, deque<int>& sol) // esta funcion se encarga de enumerar todos los caminos de un nodo a otro haciendo uso del recorrido DFS y backtracking
{
	sol.push_back(node);
	vis[node] = true;

	if(node == targeted)
	{
		int nro = sol.size();
		cout << "{";
		for(int i = 0; i < nro - 1; i++)
		{
			int elem = sol.front();
			cout << mapa1[elem] << ", ";
			sol.pop_front();
			sol.push_back(elem);
		}

		int elem = sol.front();
		cout << mapa1[elem] << "}\n";
		sol.pop_front();
		sol.push_back(elem);
	}
	else
	{
		for(int i = 0; i < adj[node].size(); i++)
		{
			if(not vis[adj[node][i]])
				absolute_router(adj[node][i], targeted, adj, vis, sol);
		}
	}
	sol.pop_back();
	vis[node] = false;
}

void dijkstra(vector<vector<pair<int, int>>> adj, int node, int targeted)
{
	int n = adj.size(), nro_procesed = 0;
	vector<int> pred(n);

	bitset<10000> procesed;

	vector<int> l(n, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	l[node] = 0;

	pred[node] = 0;
	pq.push({l[node], node});

	n--; // eliminamos el vertice 0 que ya no existe

	while(nro_procesed != n)
	{
		int u = pq.top().second;
		cout << mapa1[u] << " ";
		pq.pop();
		procesed[u] = true;
		nro_procesed++;

		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			if(procesed[v])
				continue;

			int w = adj[u][i].second;
			if(l[v] > l[u] + w)
			{
				l[v] = l[u] + w;
				pred[v] = u;
				pq.push({l[v], v});
			}
		}
	}
	cout << "\n";
}

int main()
{
	llenar_mapa();
	
	int n = 8, initial_node, targeted;

	vector<vector<int>> adj(n);
	vector<bool> vis(n, false);

	llenar_grafo_1(adj);
	
	char u, v;	
	
	cout << "a) Escriba un programa que dado dos nodos por ejemplo A y H, utilizando el algoritmo BFS muestre el camino que sigue para llegar de A a H\n";
	cout << "Introduce nodo origen y destino (ej. A H): ";
	cin >> u >> v;
	initial_node = mapa[u], targeted = mapa[v];

	bfs_enroute(initial_node, targeted, adj);
	
	cout << "\n";
	
	cout << "b) Escriba un programa que dado dos nodos por ejemplo A y H, utilizando el algoritmo DFS muestre el camino que sigue para llegar de A a H\n";
	cout << "Introduce nodo origen y destino (ej. A H): ";
	cin >> u >> v;
	initial_node = mapa[u], targeted = mapa[v];
	deque<int> solu;
	dfs_enroute(initial_node, targeted, adj, vis, solu);
	
	cout << "c) Escriba un programa que dado dos nodos se muestre todos los caminos para ir de un nodo al otro\n";
	cout << "Introduce nodo origen y destino (ej. A H): ";
	cin >> u >> v;
	initial_node = mapa[u], targeted = mapa[v];
	
	cleaning(vis);
	initial_node = mapa[u], targeted = mapa[v];
	deque<int> sol;
	absolute_router(initial_node, targeted, adj, vis, sol);
	
	cout << "e) El camino mas corto de entre dos nodos puede hallarse utilizando el algoritmo de Dijkstra. Escriba un programa que muestre el orden en que los nodos son removidos de la cola de prioridad al ejecutar el algoritmo de Dijkstra\n";
	cout << "Introduce nodo origen y destino (ej. A H): ";
	cin >> u >> v;
	vector<vector<pair<int, int>>> adj1(n);
	llenar_grafo_2(adj1);
	initial_node = mapa[u], targeted = mapa[v];
	dijkstra(adj1, initial_node, targeted);
	
	return 0;
}