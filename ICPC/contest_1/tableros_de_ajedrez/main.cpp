#include<iostream>

using namespace std;

int fibo(int n)
{
	if(n <= 2)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int T, N;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> N;
		cout << fibo(N) << "\n";
	}
	return 0;
}