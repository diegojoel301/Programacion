#include<bits/stdc++.h>
#define INF 1000000

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Point
{
	int x, y, w;

	bool operator > (const Point &other) const
	{
		return this->w > other.w;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	int t, N, M;

	cin >> t;

	while(t--)
	{
		cin >> N;
		cin >> M;

		int mat[N][M], costo[N][M];

		memset(mat, 0, sizeof mat);
		memset(costo, -1, sizeof costo);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
				cin >> mat[i][j];
		}

		priority_queue<Point, vector<Point>, greater<Point>> pq;
		costo[0][0] = mat[0][0];
		pq.push({0, 0, mat[0][0]});
		
		while(not pq.empty())
		{
			int x = pq.top().x;
			int y = pq.top().y;
			
			pq.pop();

			for(int i = 0; i < 4; i++)
			{
				int xx = x + dx[i];
				int yy = y + dy[i];

				if(xx < 0 or xx >= N or yy < 0 or yy >= M)
					continue;

				int w = mat[xx][yy];

				if(costo[x][y] + w < costo[xx][yy] or costo[xx][yy] == -1)
				{
					costo[xx][yy] = costo[x][y] + w;

					pq.push({xx, yy, costo[xx][yy]});
				}
			}
		}
		
		cout << costo[N - 1][M - 1] << "\n";

	}

	return 0;
}