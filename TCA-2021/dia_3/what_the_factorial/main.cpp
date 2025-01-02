#include<iostream>
#include<math.h>

using namespace std;

short int n;

double s = 0;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		s = s + log10(i);
	
	cout << floor(s) + 1 << "\n";
	return 0;
}