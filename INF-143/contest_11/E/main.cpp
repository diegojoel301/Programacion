#include<bits/stdc++.h>

using namespace std;

int m[1010][1010];
int dis[1010][1010];

int mov[][5] = {
 {7,  6,  5,  6,  7},
 {6,  3,  2,  3,  6},
 {5,  2,  0,  2,  5},
 {6,  3,  2,  3,  6},
 {7,  6,  5,  6,  7}

};


int main()
{
	/*
	vector<vector<int>> mov;
	mov.push_back({7,  6,  5,  6,  7});
	mov.push_back({6,  3,  2,  3,  6});
	mov.push_back({5,  2,  0,  2,  5});
	mov.push_back({6,  3,  2,  3,  6});
	mov.push_back({7,  6,  5,  6,  7});
	*/
	int r, c;

	while(cin >> r >> c)
	{
		memset(m, 0, sizeof m);

		int a, b, cc, d, w;

		cin >> a >> b >> cc >> d >> w;

		a--, b--, cc--, d--;

		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				dis[i][j] = 1e9;
				m[i][j] = 0;
			}
		}

		while(w--)
		{
			int x1, y1, x2, y2;

			cin >> x1 >> y1 >> x2 >> y2;
			x1--, y1--, x2--, y2--;
			for(int i = x1; i <= x2; i++)
			{
				for(int j = y1; j <= y2; j++)
					m[i][j] = 1;
			}
			//[distancia, [px, py]]
			priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>>>> q;

			q.push({0, {a, b}});
			dis[a][b] = 0;

			while(not q.empty())
			{
				int x = q.top().second.first;
				int y = q.top().second.second;
				q.pop();

				for(int i = x - 2; i < x + 3; i++)
				{
					for(int j = y - 2; j < y + 3; j++)
					{
						if(i >= 0 and i < r and j >= 0 and j < c and m[i][j] == 0)
						{
							int xx = i - x + 2;
							int yy = j - y + 2;
							int peso = mov[xx][yy];

							if(dis[x][y] + peso < dis[i][j])
							{
								dis[i][j] = dis[x][y] + peso;
								q.push({dis[i][j], {i, j}});
							}
						}
					}
				}
			}

			if(dis[c][d] == 1e9)
				cout << "Impossible\n";
			else
				cout << dis[c][d] << "\n";
		}

	}
	return 0;
}