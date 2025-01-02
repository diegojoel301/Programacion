#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, a, b, c, caso = 1;

	cin >> t;

	while(t--)
	{
		cin >> a >> b >> c;

		if((a <= b and b <= c) or (c <= b and b <= a))
			cout << "Case " << caso << ": " << b << "\n";
		else if((c <= a and a <= b) or (b <= a and a <= c))
			cout << "Case " << caso << ": " << a << "\n";
		else if((b <= c and c <= a) or (a <= c and c <= b))
			cout << "Case " << caso << ": " << c << "\n";
		caso++;
	}

	return 0;
}