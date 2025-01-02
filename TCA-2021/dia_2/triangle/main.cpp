#include<bits/stdc++.h>

using namespace std;

vector<int> v;
/*
	v[0] = a
	v[1] = b  a
	v[2] = c  b
	v[3] = d  c
*/
int main()
{
	for(int i = 0, value; i < 4; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());

	if((v[0] + v[1] > v[2] and v[1] + v[2] > v[0] and v[2] + v[0] > v[1]) or (v[1] + v[2] > v[3] and v[2] + v[3] > v[1] and v[3] + v[1] > v[2]))
	{
		cout << "TRIANGLE\n";
		return 0;
	}
	else
	{
		if(v[0] + v[1] == v[2] or v[0] + v[2] == v[3] or v[1] + v[2] == v[3])
		{
			cout << "SEGMENT\n";
			return 0;		
		}
		else
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}

	}

	return 0;
}