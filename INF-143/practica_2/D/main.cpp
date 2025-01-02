#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input1.txt", "r", stdin);
	char tt[200];
	cin.getline(tt, 200);

	int t = atoi(tt);

	while(t--)
	{
		string expresion;// = "([()[]()])()";
		getline(cin, expresion, '\n');
		//cin >> expresion;

		stack<char> s;

		bool flag = true;

		for(int i = 0; i < expresion.size() and flag; i++)
		{
			if(expresion[i] == '(')
				s.push('(');
			else if(expresion[i] == '[')
				s.push('[');
			else if(expresion[i] == ')')
			{
				if(s.empty())
				{
					flag = false;
					continue;
				}

				char elem = s.top();
				if(elem == '(')
					s.pop();
				else
					flag = false;
			}
			else if(expresion[i] == ']')
			{
				if(s.empty())
				{
					flag = false;
					continue;
				}

				char elem = s.top();
				if(elem == '[')
					s.pop();
				else
					flag = false;
			}
			else
				flag = false;
		}

		if(s.empty() and flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}