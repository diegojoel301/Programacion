#include<iostream>
#include<string>
#include <string.h>

using namespace std;

string num = "";

void gen()
{
	for(int i = 1; i <= 1000; i++)
		num += to_string(i);
}

int main()
{
	gen();
	/*int N;
	cin >> N;*/
	cout << num.substr(50000, 1) << "\n";
}