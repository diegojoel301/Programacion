#include<bits/stdc++.h>
#define EPS 1e-9
 
using namespace std;
 
struct point
{
	double x, y;
	point()
	{
		x = y = 0.0;
	}
	point(int _x, int _y) : x(_x), y(_y){};
 
	bool operator < (point other) const
	{
		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	};
};
 
void poinsToLine(point p1, point p2, tuple<double, double, double> &l)
{
	double la, lb, lc;

	if(fabs(p1.x-p2.x) < EPS)
	{
		la = 1.0; lb = 0.0; lc = -p1.x;
	}
	else
	{
		la = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		lb = 1.0;
		lc = -(double)(la*p1.x) - p1.y;
	}
	l = make_tuple(la, lb, lc);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, x0, y0, x, y;
 
	cin >> n >> x0 >> y0;
 
	vector<point> P;
 	set<tuple<double, double, double>> conjunto;

	point punto(x0, y0);
 
	while(n--)
	{
		cin >> x >> y;
		P.push_back(point(x, y));
	}
 
	for(int i = 0; i < P.size(); i++)
	{
		tuple<double, double, double> recta;
		poinsToLine(punto, P[i], recta);
		conjunto.insert(recta);
	}
 
	cout << conjunto.size() << "\n";
 
 
	return 0;
}