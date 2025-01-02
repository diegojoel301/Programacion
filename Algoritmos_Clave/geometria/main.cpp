#include<bits/stdc++.h>
#define EPS 1e-9
#define PI M_PI
using namespace std;

struct point
{
	double x, y;

	point()
	{
		x = y = 0;
	}
	point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec { double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVector(point a, point b)
{
	return vec(b.x-a.x, b.y-a.y);
}

double dot(vec a, vec b)
{
	return a.x*b.x + a.y*b.y;
}

double norm_sq(vec v)
{
	return v.x*v.x + v.y*v.y;
}

double angle(point a, point o, point b)
{
	vec oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b)
{
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r)
{
	return cross(toVector(p, q), toVector(p, r)) > 0;
}

bool inPolygon(point pt, const vector<point> &P)
{
	if((int)P.size() == 0)
		return false;
	double sum = 0;
	for(int i = 0; i < (int)P.size() - 1; i++)
	{
		if(ccw(pt, P[i], P[i + 1]))
			sum += angle(P[i], pt, P[i + 1]);
		else
			sum -= angle(P[i], pt, P[i + 1]);
	}

	return fabs(fabs(sum) - 2*PI) < EPS;
}

double area(const vector<point> &P)
{
	double result = 0.0, x1, y1, x2, y2;

	for(int i = 0; i < (int)P.size() - 1; i++)
	{
		x1 = P[i].x; x2 = P[i + 1].x;
		y1 = P[i].y; y2 = P[i + 1].y;
		result += (x1*y2 - x2*y1);
	}
	return fabs(result) / 2.0;
}

int main()
{
	vector<point> P;

	P.push_back(point(1, 1));
	P.push_back(point(3, 6));
	P.push_back(point(9, 1));
	P.push_back(point(12, 4));
	P.push_back(point(9, 7));
	P.push_back(point(1, 7));
	P.push_back(P[0]);

	if(inPolygon(point(5, 10), P))
		cout << "SI\n";
	else
		cout << "NO\n";

	cout << area(P) << "\n";
	cout << M_PI << "\n";
}
