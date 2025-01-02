#include<bits/stdc++.h>

using namespace std;

int SD(int n)
{
	if(n > 0)
		return (n % 10) + SD(n / 10);
	else
		return 0;
}

int main()
{
	int N, A, B, s, sd;

	while(cin >> N >> A >> B)
	{
		s = 0;

		for(int i = 1; i <= N; i++)
		{
			sd = SD(i);
			if(A <= sd and sd <= B)
				s += i;
		}
		cout << s << "\n";
	}
	return 0;
}