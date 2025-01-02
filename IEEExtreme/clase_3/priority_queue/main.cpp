#include<bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<string> cola;

	cola.push("Andres");
	cola.push("Carlos");
	cola.push("Roger");
	cola.push("Juan");
	cola.push("Yo");
	cola.push("Leydi");

	while(not cola.empty())
	{
		string elem = cola.top();

		cout << elem << "\n";

		cola.pop();
	}

	return 0;
}