#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;

	scanf("%d", &n);

	vector<pair<int, int>> in(n);

	for(pair<int, int>& p: in)
		scanf("%d%d", &p.first, $p.second);

	vector<int> indices{0} //pila de indices de maximo

	int vector_start = 0;

	int answer = 1; // el tamaño 1 es siempre posible

	// tecnica de dos punteros

	int a = 0;

	for(int b = 1; b < n; ++b)
	{
		while((int) indices.size() > vector_start and in[indices.back()].first < in[b].first)
			indices.pop_back();

		indices.push_back(b);

		while(in[indices[vector_start]].first > in[b].second)
		{
			a = indices[vector_start] + 1;
			vector_start++;
		}

		answer = max(answer, b - a + 1); //intervalo [a, b]
	}
	printf("%d\n", answer);
}