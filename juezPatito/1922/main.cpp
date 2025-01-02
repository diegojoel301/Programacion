#include<bits/stdc++.h>
#define M 9999999

using namespace std;

vector<tuple<int, bool, bool, bool>> v;

int ans = M;

void f(int pos, bool s1, bool s2, bool s3, int money)
{
	if(v.size() - 1 != pos and not (s1 and s2 and s3))
	{
		f(pos + 1, s1 or get<1>(v[pos + 1]), s2 or get<2>(v[pos + 1]), s3 or get<3>(v[pos + 1]), money + get<0>(v[pos + 1]));
		f(pos + 1, s1, s2, s3, money);
	}
	else
	{
		if(s1 and s2 and s3)
			ans = min(ans, money);
		//cout << s1 << s2 << s3 << " "<< money << "\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, dinero;

	cin >> n;

	string cad;

	while(n--)
	{
		cin >> dinero >> cad;

		bool s1 = false, s2 = false, s3 = false;

		for(int i = 0; i < cad.size(); i++)
		{
			if(cad[i] == 'F')
				s1 = true;
			else if(cad[i] == 'W')
				s2 = true;
			else if(cad[i] == 'B')
				s3 = true;
		}

		v.push_back({dinero, s1, s2, s3});

	}

	f(0, 0, 0, 0, 0);

	if(ans == M)
		cout << "-1";
	else
		cout << ans;

	return 0;
}