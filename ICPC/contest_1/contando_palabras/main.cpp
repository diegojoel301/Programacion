#include <iostream>
#include<string.h>
using namespace std;

int main()
{
	int N, cp = 0;
	cin >> N;
	cin.ignore();
	char str[100];

	cin.getline(str, N + 1);
  
    char *token = strtok(str, " ");
  
    while (token != NULL)
    {
        cp++;
        token = strtok(NULL, " ");
    }

    cout << cp << "\n";

	return 0;
}