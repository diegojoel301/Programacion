#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string one = "", two = "", three = "";

	for(int i = 0; i < n; i++)
	{
		one = one + " (^v^)  ";
		two = two + "<(   )> ";
		three = three + "  W W   ";
	}

	cout << one << "\n" << two << "\n" << three << "\n";
	return 0;
}