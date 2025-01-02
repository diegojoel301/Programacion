#include<bits/stdc++.h>
using namespace std;

int n, p[30000010];
set<int> st;
void init()
{
	for(int i = 0; i < 30000010; i++)
		p[i] = i;
}

int find(int x)
{
	if(x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void Union(int x, int y)
{
	int px = find(x);
	int py = find(y);

	st.erase(py);
	p[py] = px;
	st.insert(px);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();

	cin >> n;

	//int dx = 0;
	//int dy = 1000001;
	int ver = 200005;

	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		y += 100001;
		int actual = ver + i;
		Union(actual, x);
		Union(actual, y);

	}

	
	double ans;

	ans = st.size();

	int m;

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int x, y;
		int actual = ver + n + i;
		cin >> x >> y;
		y += 100001;
		Union(actual, x);
		Union(actual, y);

		st.insert(find(actual));
		ans += st.size();
	}
	cout.precision(2);
	cout << fixed << ans / (m + 1);
	
	return 0;
}