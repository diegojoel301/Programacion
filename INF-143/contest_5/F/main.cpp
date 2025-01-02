#include<bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

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
   int N;
   while(cin >> N)
   {
      vector<pair<ll, ll>> v;
      ll x, y;

      while(N--)
      {
         cin >> x >> y;

         v.push_back(make_pair(x, y));
      }
      
      ll perimetro = boundary(v);
      ld area = polygonArea(v);
      ll interior = area - (perimetro / 2) + 1;
      printf("%.1f\n", (double)area);
      cout << perimetro << "\n" << interior << "\n";
   }
   return 0;
}