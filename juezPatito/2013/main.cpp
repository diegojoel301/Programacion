#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b, c, d, vacio;

	while(getline(cin, a, '\n'))
	{
		getline(cin, b, '\n');
		getline(cin, c, '\n');
		getline(cin, d, '\n');
		bool flag = true;

		if((a[2] == '1' and b[2] == '5' and c[2] == '6' and d[2] == '2') or (a[2] == '1' and b[2] == '2' and c[2] == '6' and d[2] == '5') or (a[2] == '6' and b[2] == '5' and c[2] == '1' and d[2] == '2') or (a[2] == '6' and b[2] == '2' and c[2] == '1' and d[2] == '5') or (a[2] == '5' and b[2] == '1' and c[2] == '2' and d[2] == '6') or (a[2] == '5' and b[2] == '6' and c[2] == '2' and d[2] == '1') or (a[2] == '2' and b[2] == '1' and c[2] == '5' and d[2] == '6') or (a[2] == '2' and b[2] == '6' and c[2] == '5' and d[2] == '1'))
		{
			if(a.size() == 5)
			{
				if((a[0] == '3' and a[4] == '4') or (a[0] == '4' and a[4] == '3'))
					flag = true;
				else
				{
					cout << "Mal\n";
					flag = false;
					continue;
				}
			}

			if(b.size() == 5)
			{
				if((b[0] == '3' and b[4] == '4') or (b[0] == '4' and b[4] == '3'))
					flag = true;
				else
				{
					cout << "Mal\n";
					flag = false;
					continue;
				}
			}

			if(c.size() == 5)
			{
				if((c[0] == '3' and c[4] == '4') or (c[0] == '4' and c[4] == '3'))
					flag = true;
				else
				{
					cout << "Mal\n";
					flag = false;
					continue;
				}
			}

			if(d.size() == 5)
			{
				if((d[0] == '3' and d[4] == '4') or (d[0] == '4' and d[4] == '3'))
					flag = true;
				else
				{
					cout << "Mal\n";
					flag = false;
					continue;
				}
			}
		}
		else
		{
			cout << "Mal\n";
			flag = false;
			continue;
		}
		
		if(flag)
			cout << "Bien\n";

	}
	
	return 0;
}