#include<bits/stdc++.h>
#define INF 100000000
using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>> lista_adyacencia, vector<int> S)
{
	int n = lista_adyacencia.size(), procesados = 0;

	bitset<10000> procesado;

	vector<int> l(n, INF); // Asignacion de etiquetas

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cola_prioridad;

	for(auto s: S) //S es de sources origenes y todos estos deberan estar en 0 ya no en INF
	{
		l[s] = 0;
		cola_prioridad.push(make_pair(l[s], s));
	}

	n--;

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
				l[v] = l[u] + w;
		}
	}
	return l;
}

void solucion()
{
	int N, V;

	cin >> N >> V;

	vector<vector<pair<int, int>>> lista_adyacencia(N + 1);

	for(int i = 0, u, v, w; i < V; i++)
	{
		cin >> u >> v >> w;

		lista_adyacencia[u].push_back(make_pair(v, w));
	}

	vector<int> bomberos, edificios;

	int n_bomb, b, i, n_edif, e;

	cin >> n_bomb >> n_edif;

	for(i = 0; i < n_bomb; i++)
	{
		cin >> b;
		bomberos.push_back(b);
	}

	for(i = 0; i < n_edif; i++)
	{
		cin >> e;
		edificios.push_back(e);
	}

	auto l = Dijkstra(lista_adyacencia, bomberos);
	for(int &e: edificios)
		cout << e << " " << l[e] << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);
	solucion();
	return 0;
}