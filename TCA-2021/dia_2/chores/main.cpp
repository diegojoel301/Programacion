#include<iostream>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

//int n, a, b, c = 0, my = -1, mn = 99999999;
int n, a, b;

vector<int> v;

int main()
{
	cin >> n >> a >> b;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
		/*
		if(value > my)
			my = value;
		if(value < mn)
			mn = value; 
		*/
	}

	/*
	for(int x = mn, ap, bp; x <= my; x++)
	{
		ap = bp = 0;

		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] > x)
				ap++;
			else
				bp++;
		}
		if(ap == a and bp == b)
			c++;
	}
	*/
	sort(v.begin(), v.end());
	cout << abs(v[b - 1] - v[b]) << "\n";

	return 0;
}