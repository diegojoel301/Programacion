#include<bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

//puntos en los limites
ll boundary(vector<pair<ll, ll>> &A)
{
	ll ats = A.size();

	for(int i = 0; i < A.size(); i++)
	{
		ll dx = (A[i].first - A[(i + 1) % A.size()].first);
		ll dy = (A[i].second - A[(i + 1) % A.size()].second);
		ats += abs(__gcd(dx, dy)) - 1;
	}

	return ats;
}

ld cross(ld x1, ld y1, ld x2, ld y2)
{
   return x1*y2 - x2*y1;
}

ld polygonArea(vector<pair<ll, ll>> &A)
{
   ld ats = 0.0;

   for(int i = 2; i < A.size(); i++)
      ats += cross(A[i].first - A[0].first, A[i].second - A[0].second, A[i - 1].first - A[0].first, A[i - 1].second - A[0].second);

   return fabs(ats / 2);
}

int main()
{
	//vector<pair<ll, ll>> v = {make_pair(2, 1), make_pair(5, 4), make_pair(5, 6), make_pair(1, 4)};
	vector<pair<ll, ll>> v = {make_pair(4, 5), make_pair(7, 7), make_pair(9, 5), make_pair(1, 2), make_pair(4, 1), make_pair(8, 1)};

	cout << boundary(v) << "\n";
	return 0;
}