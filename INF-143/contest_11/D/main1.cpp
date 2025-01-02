#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> a;
int vis[30][30];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<char> b, bb, bbb;

	for(char i = 'a'; i <= 'j'; ++i)
		b.push_back(i);

	for(char i = 'k'; i <= 't'; ++i)
		bb.push_back(i);

	for(char i = 'u'; i <= 'z'; ++i)
		bbb.push_back(i);	

	bbb.push_back('@'); //esp
	bbb.push_back('!'); //enter
	bbb.push_back('-'); //bks

	a.push_back(b);
	a.push_back(bb);
	a.push_back(bbb);

	int t;

	cin >> t;

	cin.ignore();

	while(t--)
	{
		string s;

		getline(cin, s);

		int x = 0, y = 0, res = 0;

		auto bfs = [&] (int xx, int yy, char m)
		{
			queue<pair<int, int>> q;
			q.push({xx, yy});
			memset(vis, -1, sizeof vis);

			vis[xx][yy] = 0;

			while(not q.empty())
			{
				xx = q.front().first;
				yy = q.front().second;
				q.pop();

				if(a[xx][yy] == m)
				{
					x = xx;
					y = yy;

					return vis[xx][yy];
				}

				for(int i = 0; i < 4; i++)
				{
					int u = dx[i] + xx;
					int v = dy[i] + yy;

					if(u >= 0 and u < a.size() and v >= 0 and v < a[0].size() and vis[u][v] == -1)
					{
						vis[u][v] = vis[xx][yy] + 1;
						q.push({u, v});
					}

				}
			}

			return -1;
		};

		for(char c: s)
			res += bfs(x, y, c != ' ' ? c : '@');

		res += bfs(x, y, '!');

		cout << res << "\n";


	}

	return 0;
}