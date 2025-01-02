#include<bits/stdc++.h>

using namespace std;

string transform(int time)
{	
	if(time > 18000)
		return "Signals fail to synchronise in 5 hours";
	int hr = (time / 3600) % 60, min = (time / 60) % 60, seg = time % 60;
	string ans = "";

	if(hr <= 9)
		ans += "0" + to_string(hr) + ":";
	else
		ans += to_string(hr) + ":";

	if(min <= 9)
		ans += "0" + to_string(min) + ":";
	else
		ans += to_string(min) + ":";
	
	if(seg <= 9)
		ans += "0" + to_string(seg);
	else
		ans += to_string(seg);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input1.txt", "r", stdin);

	while(true)
	{
		int x;

		vector<tuple<char, int, int>> v; // color de semaforo, tiempo que corresponde al semaforo, tiempo que varia
		
		while(true)
		{
			cin >> x;

			if(x == 0)
				break;

			v.push_back({'v', x, x});
		}

		if(v.size() == 0)
			break;

		int ans = 0;

		bool bandera = true;

		while(true)
		{
			// este for es para buscar al menor
			int mn = 100000;

			for(int j = 0; j < v.size(); j++)
				mn = min(mn, get<2>(v[j]));
			ans += mn;
			// este for es para modificar el vector de semaforos

			if(ans - 5 > 18000)
			{
				cout << "Signals fail to synchronise in 5 hours\n";
				bandera = false;
				break;
			}

			for(int j = 0; j < v.size(); j++)
			{
				char color = get<0>(v[j]);
				int time_mod = get<2>(v[j]) - mn, time = get<1>(v[j]);

				if(time_mod == 0)
				{
					if(color == 'v')
						v[j] = {'n', time, 5};
					else if(color == 'n')
						v[j] = {'r', time, time};
					else if(color == 'r')
						v[j] = {'v', time, abs(time - 5)};
				}
				else
					v[j] = {color, time, time_mod};
			}

			// este for es para verificar si todos los semaforos estan en verde

			int c = 0;

			for(int j = 0; j < v.size(); j++)
			{
				if(get<0>(v[j]) == 'v')
					c++;
			}
			if(c == v.size())
				break;
		}

		//for(int i = 0; i < v.size(); i++)
		//	cout << "Semaforo " << i << ": " << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
		if(bandera)
		{
			ans = ans - 5;
			cout << transform(ans) << "\n";
		}

	}
	return 0;
}