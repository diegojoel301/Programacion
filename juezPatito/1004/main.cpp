#include<bits/stdc++.h>

using namespace std;

char str[1010][1010]; // matriz con el tamaño amximo
int D[1010][1010]; // costo para llegar a tal posicion
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n, m;

bool ok(int x, int y) //esto sirve para verificar que no me sali de la matriz
{
	return x >= 0 and x < n and y >= 0 and y < m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	for(int cases = 1; cases <= t; cases++)
	{
		cin >> n >> m;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> str[i][j];
				D[i][j] = 1e9; //inicializo todo en un numero grande
			}
		}

		int cx, cy; // esquina superior izquierda(partida)
		int px, py; // esquina inferior derecha(destino)

		cin >> cx >> cy;
		cin >> px >> py;

		if(str[cx][cy] == '.') // esta libre
			D[cx][cy] = 0; // costo 0
		else
			D[cx][cy] = 1;

		queue<pair<int, int>> q; // cola de pares
		q.push(make_pair(cx, cy)); // pusheamos la posicion

		while(not q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for(int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(ok(nx, ny))
				{
					int cost = 0; // cuanto me cuesta llegar ahi
					if(str[nx][ny] == '#')
						cost = 1; // se incrementa aqui ya que se tendra que romper esta pared
					if(D[x][y] + cost < D[nx][ny])
					{
						D[nx][ny] = D[x][y] + cost;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		cout << "Laberinto #" << cases << ": " << D[px][py] << "\n";
		
	}
}