#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int A[N];
int ST[4 * N];

void build(int node, int a, int b) // Costo O(n)
{
	int mid = (a + b) / 2;

	// caso base

	if(a == b)
	{
		ST[node] = A[a];
		return;
	}


	// construyendo el hijo izquierdo
	build(node * 2, a, mid);
	// construyendo el hijo derecho
	build(node * 2 + 1, mid + 1, b);
	// fin de la construccion

	ST[node] = min(ST[node * 2], ST[node * 2 + 1]);
}

int query(int node, int a, int b, int l, int r)
{
	if(a >= l and b <= r) // caso base
		return ST[node];
	int mid = (a + b) / 2;

	if(r <= mid) // necesitamos al hijo izquierdo
		return query(node * 2, a, mid, l, r);
	if(l > mid) // necesitamos al hijo derecho
		return query(node * 2 + 1, mid + 1, b, l, r);

	return min(query(node * 2, a, mid, l, r), query(node * 2  + 1, mid + 1, b, l, r)); // aca necesitamos a los 2
}

void update(int node, int a, int b, int pos, int value)
{
	int mid = (a + b) / 2;

	if(a == b)
		ST[node] = value;
	else
	{
		if(pos <= mid)
			update(node * 2, a, mid, pos, value);
		else
			update(node * 2 + 1, mid + 1, b, pos, value);

		ST[node] = min(ST[node * 2], ST[node * 2 + 1 ]);
	}
}

int main()
{
	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> A[i];

	build(1, 0, n - 1);

	int consultas;

	cin >> consultas;

	while(consultas--)
	{
		int l, r;

		cin >> l >> r;

		cout << query(1, 0, n - 1, l, r) << "\n";
	}

	update(1, 0, n - 1, 3, 0);


	return 0;
}
