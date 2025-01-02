#include<bits/stdc++.h>

using namespace std;

void update(queue<tuple<int, int, int>> &q, map<int, pair<int, int>> map_work_maintence, vector<int> &sol, int k, int posv)
{
	int size = q.size();

	for(int i = 0, work_map, maintence_map, work_elem, maintence_elem; i < size; i++)
	{
		tuple<int, int, int> elem = q.front();

		q.pop();

		if(get<0>(elem) != k)
		{
		
			work_map = map_work_maintence[get<0>(elem)].first;
			maintence_map = map_work_maintence[get<0>(elem)].second;
			work_elem = get<1>(elem);
			maintence_elem = get<2>(elem);
			if(maintence_elem == 0)
			{
				if(work_elem == work_map)
					maintence_elem++;
				else
					work_elem++;
			}
			else if(work_elem == work_map)
			{
				if(maintence_elem == maintence_map)
				{
					work_elem = 1;
					maintence_elem = 0;
				}
				else
					maintence_elem++;
			}

			q.push(make_tuple(get<0>(elem), work_elem, maintence_elem));

			if(maintence_elem > 0)
				sol[posv]++;

		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, op, k;

	cin >> n >> m;

	map<int, pair<int, int>> map_work_maintence;

	for(int i = 1, work, maintence; i <= n; i++)
	{
		cin >> work >> maintence;
		map_work_maintence[i] = make_pair(work, maintence);	
	}

	queue<tuple<int, int, int>> q;
	vector<int> sol(m, 0);
	
	for(int days = 0, pos = 0; days < m; days++, pos++)
	{
		cin >> op >> k;

		if(op == 1)
		{
			update(q, map_work_maintence, sol, -1, pos);
			q.push(make_tuple(k, 1, 0));
		}
		else
			update(q, map_work_maintence, sol, k, pos);
	}
	
	for(int i = 0; i < m; i++)
		cout << sol[i] << "\n";

	return 0;
}