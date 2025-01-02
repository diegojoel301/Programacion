#include<bits/stdc++.h>
#define EPS 1e-9
#define PI 2 * acos(0.0)

using namespace std;

struct point
{
	double x, y;

	point()
	{ x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y){}
	bool operator < (point other) const
	{
		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

struct vec
{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

struct terna
{
	double distancia;
	point punto;
	int id;

	terna(double d, point p, int i) : distancia(d), punto(p), id(i){}

	bool operator < (terna other) const
	{
		return distancia < other.distancia;
	}

};

vec toVector(point a, point b)
{
	return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b)
{
	return a.x * b.x + a.y * b.y;
}

double norm_sq(vec v)
{
	return v.x * v.x + v.y * v.y;
}

double angle(point a, point o, point b)
{
	vec oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa)* norm_sq(ob)));
}

point get_referencia(point center, double distancia)
{
	return point(center.x, center.y + distancia);
}

double distance(point a, point b)
{
	return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}

void dfs(const vector<vector<int>>& adj, vector<bool>& vis, int node)
{
	vis[node] = true;

	for(int i = 0; i < adj[node].size(); i++)
	{
		if(not vis[adj[node][i]])
			dfs(adj, vis, adj[node][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	int n;
	double x, y;

	while(true)
	{
		cin >> n;

		if(n == 0)
			break;

		if(n == 1)
		{
			cin >> x >> y;
			cout << "Chapare protegido\n";
			continue;
		}

		vector<vector<int>> adj(n);
		vector<bool> vis(n, false);

		vector<pair<point, int>> vp;

		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			vp.push_back({{x, y}, i});
		}

		for(int i = 0; i < vp.size(); i++)
		{
			priority_queue<terna> pq;

			for(int j = 0; j < vp.size(); j++)
			{
				if(i != j)
					pq.push({-distance(vp[i].first, vp[j].first), vp[j].first, j});
			}

			
			adj[i].push_back(pq.top().id);
			pq.pop();
			adj[i].push_back(pq.top().id);
			
		}

		dfs(adj, vis, 0);

		bool flag = true;

		for(int i = 0; i < vis.size(); i++)
			flag = flag & vis[i];

		if(flag)
			cout << "Chapare protegido\n";
		else
			cout << "Chapare no Protegido\n";

	}

	return 0;
}