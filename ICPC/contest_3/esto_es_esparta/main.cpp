#include<bits/stdc++.h>

using namespace std;

string cad, name;

int main()
{
	while(cin >> cad)
	{
		name = "";
		stack<int> s;
		
		for(int i = 0, a, b; i < cad.length(); i++)
		{
			if(48 <= (int)cad[i] and (int)cad[i] <= 57)
				s.push((int)cad[i] - 48);
			else if(cad[i] == '+')
			{
				a = s.top(); s.pop();
				b = s.top(); s.pop();
				s.push(a + b);
			}
			else if(cad[i] == '*')
			{
				a = s.top(); s.pop();
				b = s.top(); s.pop();
				s.push(a * b);
			}
			else
				name += cad[i];
		}

		reverse(name.begin(), name.end());

		cout << name << ": habilidad " << s.top() << "\n";
	}

	return 0;
}