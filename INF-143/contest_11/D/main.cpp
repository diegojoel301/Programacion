#include<bits/stdc++.h>
#define INF 100000000

using namespace std;

vector<vector<int>> adj(130);

void gen()
{
	adj[(int)'a'].push_back((int)'b');
	adj[(int)'a'].push_back((int)'k');
	adj[(int)'b'].push_back((int)'a');
	adj[(int)'b'].push_back((int)'l');
	adj[(int)'b'].push_back((int)'c');
	adj[(int)'c'].push_back((int)'b');
	adj[(int)'c'].push_back((int)'d');
	adj[(int)'c'].push_back((int)'m');
	adj[(int)'d'].push_back((int)'c');
	adj[(int)'d'].push_back((int)'n');
	adj[(int)'d'].push_back((int)'e');
	adj[(int)'e'].push_back((int)'d');
	adj[(int)'e'].push_back((int)'o');
	adj[(int)'e'].push_back((int)'f');
	adj[(int)'f'].push_back((int)'e');
	adj[(int)'f'].push_back((int)'p');
	adj[(int)'f'].push_back((int)'g');
	adj[(int)'g'].push_back((int)'f');
	adj[(int)'g'].push_back((int)'q');
	adj[(int)'g'].push_back((int)'h');
	adj[(int)'h'].push_back((int)'g');
	adj[(int)'h'].push_back((int)'r');
	adj[(int)'h'].push_back((int)'i');
	adj[(int)'i'].push_back((int)'h');
	adj[(int)'i'].push_back((int)'s');
	adj[(int)'i'].push_back((int)'j');
	adj[(int)'j'].push_back((int)'i');
	adj[(int)'j'].push_back((int)'t');
	adj[(int)'k'].push_back((int)'a');
	adj[(int)'k'].push_back((int)'l');
	adj[(int)'k'].push_back((int)'u');
	adj[(int)'l'].push_back((int)'b');
	adj[(int)'l'].push_back((int)'k');
	adj[(int)'l'].push_back((int)'v');
	adj[(int)'l'].push_back((int)'m');
	adj[(int)'m'].push_back((int)'c');
	adj[(int)'m'].push_back((int)'l');
	adj[(int)'m'].push_back((int)'n');
	adj[(int)'m'].push_back((int)'w');
	adj[(int)'n'].push_back((int)'d');
	adj[(int)'n'].push_back((int)'m');
	adj[(int)'n'].push_back((int)'o');
	adj[(int)'n'].push_back((int)'x');
	adj[(int)'o'].push_back((int)'e');
	adj[(int)'o'].push_back((int)'n');
	adj[(int)'o'].push_back((int)'p');
	adj[(int)'o'].push_back((int)'y');
	adj[(int)'p'].push_back((int)'f');
	adj[(int)'p'].push_back((int)'o');
	adj[(int)'p'].push_back((int)'q');
	adj[(int)'p'].push_back((int)'z');
	adj[(int)'q'].push_back((int)'g');
	adj[(int)'q'].push_back((int)'p');
	adj[(int)'q'].push_back((int)'r');
	adj[(int)'q'].push_back((int)' ');
	adj[(int)'r'].push_back((int)'h');
	adj[(int)'r'].push_back((int)'q');
	adj[(int)'r'].push_back((int)'s');
	adj[(int)'r'].push_back((int)' ');

	adj[(int)'s'].push_back((int)'i');
	adj[(int)'s'].push_back((int)'r');
	adj[(int)'s'].push_back((int)'t');
	adj[(int)'s'].push_back((int)'\n');

	adj[(int)'t'].push_back((int)'j');
	adj[(int)'t'].push_back((int)'s');
	adj[(int)'t'].push_back((int)'\n');
	adj[(int)'u'].push_back((int)'k');
	adj[(int)'u'].push_back((int)'v');
	adj[(int)'v'].push_back((int)'l');
	adj[(int)'v'].push_back((int)'u');
	adj[(int)'v'].push_back((int)'w');
	adj[(int)'w'].push_back((int)'m');
	adj[(int)'w'].push_back((int)'v');
	adj[(int)'w'].push_back((int)'x');

	adj[(int)'x'].push_back((int)'n');
	adj[(int)'x'].push_back((int)'w');
	adj[(int)'x'].push_back((int)'y');

	adj[(int)'y'].push_back((int)'o');
	adj[(int)'y'].push_back((int)'z');
	adj[(int)'y'].push_back((int)'x');

	adj[(int)'z'].push_back((int)'p');
	adj[(int)'z'].push_back((int)'y');
	adj[(int)'z'].push_back((int)' ');

	adj[(int)' '].push_back((int)'q');
	adj[(int)' '].push_back((int)'z');
	adj[(int)' '].push_back((int)'r');
	adj[(int)' '].push_back((int)'\n');

	adj[(int)'\n'].push_back((int)' ');
	adj[(int)'\n'].push_back((int)'s');
	adj[(int)'\n'].push_back((int)'t');

}

void camino_minimo(int s, int t)
{
	int n = 28;

	bitset<10000> procesado;

	vector<int> l(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	l[s] = 0;
	pred[s] = 0;
	pq.push(make_pair(0, s));

	n--;

	while(not pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		procesado[u] = true;

		

	}

}

int main()
{
	gen();



	return 0;
}