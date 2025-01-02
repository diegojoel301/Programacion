#include<bits/stdc++.h>
#define INF 1e8

using namespace std;

vector<int> Dijkstra_ruta(vector<vector<pair<int, int>>> lista_adyacencia, int s, int t)
{
	int n = lista_adyacencia.size(), procesados = 0;
	vector<int> pred(n); // vector de predesesores
	bitset<10000> procesado;
	vector<int> l(n, INF); // Asignacion de etiquetas
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cola_prioridad;

	l[s] = 0;
	pred[s] = 0; //null

	cola_prioridad.push(make_pair(l[s], s));

	n--; //eliminamos el vertice 0, no existe

	while(procesados != n)
	{
		int u = cola_prioridad.top().second;
		cola_prioridad.pop();
		procesado[u] = true;
		procesados++;

		for(auto &par: lista_adyacencia[u])
		{
			int v = par.first;
			if(procesado[v])
				continue;

			int w = par.second;

			if(l[v] > l[u] + w)
			{
				l[v] = l[u] + w;
				pred[v] = u;
				cola_prioridad.push(make_pair(l[v], v));
			}
		}
	}

	cout << l[t] << "\n";

	//para reconstruir la ruta

	vector<int> sucesion;

	while(t)
	{
		sucesion.push_back(t);
		t = pred[t];
	}

	reverse(sucesion.begin(), sucesion.end());

	return sucesion;

}

int main()
{
	freopen("input.txt", "r", stdin);

	int v1, v2, n, vertices;
	cin >> n;
	cin >> vertices;
	vector<vector<pair<int, int>>> lista_adyacencia(n + 1);
	for(int i = 0, u, v, w; i < vertices; i++)
	{
		cin >> u >> v >> w;
		lista_adyacencia[u].push_back(make_pair(v, w));
	}
	
	cin >> v1;
	cin >> v2;

	auto sucesion = Dijkstra_ruta(lista_adyacencia, v1, v2);

	for(int vertice: sucesion)
		cout << vertice << " ";
	cout << "\n";
	

	for(int i = 0; i < lista_adyacencia.size(); i++)
	{
		cout << i << ": ";
		for(int j = 0; j < lista_adyacencia[i].size(); j++)
			cout << "(" << lista_adyacencia[i][j].first << ", " << lista_adyacencia[i][j].second << "), ";
		cout << "\n";
	}

	return 0;
}