#include<iostream>
#include<queue>

using namespace std;

queue<char> v;

string skill(string in)
{
	if(in == "QQQ")
		return "Cold Snap\n";
	if(in == "QQW" or in == "WQQ" or in == "QWQ")
		return "Ghost Walk\n";
	if(in == "WWQ" or in == "WQW" or in == "QWW")
		return "Tornado\n";		
	if(in == "WWW")
		return "EMP\n";
	if(in == "WWE" or in == "WEW" or in == "EWW")
		return "Alacrity\n";
	if(in == "EEW" or in == "EWE" or in == "WEE")
		return "Chaos Meteor\n";
	if(in == "EEE")
		return "Sunstrike\n";
	if(in == "EEQ" or in == "EQE" or in == "QEE")
		return "Forge Spirit\n";
	if(in == "QQE" or in == "QEQ" or in == "EQQ")
		return "Ice Wall\n";
	if(in == "QWE" or in == "WEQ" or in == "EQW" or in == "WQE" or in == "QEW" or in == "EWQ")
		return "Deafening Blast\n";
	return "None\n";
}

void mostrarSkill()
{
	if(v.size() != 3)
	{
		while(not v.empty())
			v.pop();
		cout << "None\n";
	}
	else
	{
		string str = "";

		for(int i = 0; i < 3; i++)
		{
			char value = v.front();
			str += value;
			v.pop();
			v.push(value);
		}
		cout << skill(str);
		v.pop();
	}
	
}

int main()
{
	string s; cin >> s;

	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != 'R')
			v.push(s[i]);
		else
			mostrarSkill();
	}
	return 0;
}