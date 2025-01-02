#include<bits/stdc++.h>

using namespace std;

int main()
{
	string al;

	vector<vector<string>> res;

	while(cin >> al)
	{
		int n;
		cin >> n;
		cin.ignore();

		unordered_map<char, char> dict;

		for(int i = 0; i < (int)al.size(); i++)
			dict[al[i]] = (char)(i + 'a');
		vector<string> ans;
		while(n--)
		{
			string s;
			getline(cin, s);
			string actual = "";
			for(auto c: s)
			{
				if(dict.count(c)) actual += dict[c];
				else actual += " ";
			}
			ans.push_back(actual);
		}
		res.push_back(ans);
	}

	for(int i = 0; i < (int)res.size(); ++i)
	{
		for(auto &cad: res[i])
		{
			while(cad.back() == ' ')
				cad.pop_back();
			cout << cad << "\n";
		}
		cout << "\n";
	}

	return 0;
}
