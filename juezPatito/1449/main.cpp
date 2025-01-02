#include<bits/stdc++.h>

using namespace std;

int main()
{
	int A, B, N, sum;

	while(cin >> A >> B)
	{
		cin >> N;
		sum = 0;
		for(int i = 0, value; i < N; i++)
		{
			cin >> value;
			if(A <= value and value <= B)
				sum += value;
		}
		cout << sum << "\n";
	}
}