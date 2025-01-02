#include<bits/stdc++.h>
#include<string>

using namespace std;

string ordenar(string a)
{
	sort(a.begin(), a.end());
	return a;
}

void remove(vector<string> &v)
{
	auto end = v.end();

	for(auto it = v.begin(); it != end; it++)
		end = remove(it +1 , end, *it);
	v.erase(end, v.end());
}

void permute(string s, string answer)
{
	if(s.length() == 0)
	{
		cout << answer << "\n";
		return;
	}
	for(int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		string left_substr = s.substr(0, i);
		string right_substr = s.substr(i + 1);
		string res = left_substr + right_substr;
		permute(res, answer + ch);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	string cad;

	for(int i = 0; i < n; i++)
	{
		cin >> cad;
		string answer = "";
		if(next_permutation(cad.begin(), cad.end()))
		{
			
			permute(cad, answer);
			
		}
		else
			cout << cad << "\n";

	}

	return 0;
}