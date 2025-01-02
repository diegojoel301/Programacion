#include<bits/stdc++.h>

using namespace std;

int invierte(int x)
{
	int y = 0;

	while(x > 0)
	{
		y = (y * 10) + (x % 10);
		x /= 10; 
	}

	return y;
}

void f(int x, int y)
{
	/*
	int ans = 0;

	while(ans != 10)
	{
		cout << y << "\n";
		int inv = invierte(y);

		if(inv < y - 1)
			y = inv;
		else
			y--;
		ans++;
	}
	*/

	
	
	//return ans;
}

int main()
{
	/*
	int x, y, t, A, B;

	cin >> t;

	while(t--)
	{
		cin >> A >> B;

		cout << f(A, B) << "\n";
	}
	*/

	f(100, 301);

	return 0;
}