#include<bits/stdc++.h>

using namespace std;

int BS(vector<int> v, int x)
{
	int low = 0, high = v.size() - 1;

	while(low <= high)
	{
		int mid = (high + low) / 2;

		if(v[mid] > x)
			high = mid - 1;
		else if(v[mid] < x)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int main()
{
	int N, P, S, s = 0;
	cin >> N >> P;
	vector<int> v(N);

	for(int i = 0, value; i < N; i++)
	{
		cin >> value;
		s += value;
		
		v[i] = s;
	}

	while(P--)
	{
		cin >> S;
		int res = BS(v, S);

		if(res != -1)
			cout << res << "\n";
		else
			cout << "No existe\n";
	}

	return 0;
}